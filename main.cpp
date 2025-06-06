#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <limits>
#include <ctime>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>

// ANSI color codes (cross-platform terminals)
const std::string RESET   = "\033[0m";
const std::string RED     = "\033[31m";
const std::string GREEN   = "\033[32m";
const std::string YELLOW  = "\033[33m";
const std::string BLUE    = "\033[34m";
const std::string CYAN    = "\033[36m";
const std::string WHITE   = "\033[37m";

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class NumberAnalyzer {
private:
    std::vector<float> numbers;
    std::string logFile    = "program.log";
    std::string resultFile = "results.txt";

    void logMessage(const std::string& message) {
        std::ofstream log(logFile, std::ios::app);
        auto now = std::time(nullptr);
        log << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S")
            << " | " << message << "\n";
    }

    void displayHeader() {
        clearScreen();
        std::cout << CYAN
                  << R"(
     ___    __   __
    / _ \   \ \ / /
   / /_\ \   \ V / 
  / /_ _\ \   | |  
 / / | | \ \  | |  
/_/  |_|  \_\ |_|  
)" << RESET
                  << WHITE << "           Version 2.0 by Adrian Lesniak\n\n" << RESET;
    }

    float calculateAverage() const {
        float sum = 0;
        for (auto n : numbers) sum += n;
        return sum / numbers.size();
    }

    bool saveToFile(float closest) {
        std::ofstream file(resultFile, std::ios::app);
        if (!file) {
            logMessage("Failed to open results.txt for writing");
            return false;
        }
        file << std::fixed << std::setprecision(2)
             << "Average: " << calculateAverage()
             << " | Closest: " << closest << "\n";
        return true;
    }

public:
    bool inputNumbers() {
        displayHeader();
        std::cout << YELLOW << " Enter 5 numbers to analyze:\n" << RESET;
        numbers.clear();

        for (int i = 1; i <= 5; ++i) {
            float num;
            std::cout << GREEN << "  [" << i << "] " << RESET;
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                logMessage("Invalid numeric input");
                std::cout << RED << "\n  Invalid input; please enter a number.\n" << RESET;
                return false;
            }
            numbers.push_back(num);
        }
        return true;
    }

    float findClosestNumber() {
        float avg = calculateAverage();
        float bestDiff = std::numeric_limits<float>::max();
        float closest = numbers[0];
        for (auto n : numbers) {
            float diff = std::abs(n - avg);
            if (diff < bestDiff) {
                bestDiff = diff;
                closest = n;
            }
        }
        if (!saveToFile(closest)) {
            std::cout << RED << "  Warning: could not save results to file.\n" << RESET;
        }
        return closest;
    }

    void displayResults(float closest) {
        float avg = calculateAverage();
        std::cout << YELLOW
                  << "\n+-----------------------------------------+\n"
                  << "|               Results                  |\n"
                  << "+-----------------------------------------+\n"
                  << RESET;
        std::cout << "  " << BLUE << "Average:        " << RESET
                  << std::fixed << std::setprecision(2) << avg << "\n";
        std::cout << "  " << BLUE << "Closest number: " << RESET
                  << std::fixed << std::setprecision(2) << closest << "\n";
        std::cout << YELLOW
                  << "+-----------------------------------------+\n"
                  << RESET;
        logMessage("Computed avg=" + std::to_string(avg)
                   + " closest=" + std::to_string(closest));
    }

    void viewLog() {
        displayHeader();
        std::ifstream log(logFile);
        std::cout << YELLOW << "\n  -- Program Log --\n\n" << RESET;
        if (!log) {
            std::cout << RED << "  No log file found.\n" << RESET;
        } else {
            std::string line;
            while (std::getline(log, line)) {
                std::cout << "  " << line << "\n";
            }
        }
        std::cout << "\n  Press Enter to return to menu...";
        std::cin.ignore();
        std::cin.get();
    }

    void viewResultsFile() {
        displayHeader();
        std::ifstream res(resultFile);
        std::cout << YELLOW << "\n  -- Saved Results --\n\n" << RESET;
        if (!res) {
            std::cout << RED << "  No results file found.\n" << RESET;
        } else {
            std::string line;
            while (std::getline(res, line)) {
                std::cout << "  " << line << "\n";
            }
        }
        std::cout << "\n  Press Enter to return to menu...";
        std::cin.ignore();
        std::cin.get();
    }
};

int main() {
    NumberAnalyzer analyzer;
    while (true) {
        clearScreen();
        std::cout << CYAN
                  << "\n+------------- Main Menu --------------+\n"
                  << "| 1) Analyze 5 numbers                 |\n"
                  << "| 2) View saved results                |\n"
                  << "| 3) View program log                  |\n"
                  << "| 4) Exit                              |\n"
                  << "+--------------------------------------+\n"
                  << RESET;

        std::cout << GREEN << "  Enter choice (1-4): " << RESET;
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                if (analyzer.inputNumbers()) {
                    float closest = analyzer.findClosestNumber();
                    analyzer.displayResults(closest);
                    // **Consume leftover newline** then wait for Enter:
                    std::cout << GREEN << "\n  Press Enter to return to menu..." << RESET;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();
                }
                break;
            }
            case 2:
                analyzer.viewResultsFile();
                break;
            case 3:
                analyzer.viewLog();
                break;
            case 4:
                std::cout << YELLOW << "\n  Thank you for using Number Analyzer!\n" << RESET;
                return 0;
            default:
                std::cout << RED << "  Invalid option, try again.\n" << RESET;
                std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    return 0;
}
