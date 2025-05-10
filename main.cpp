#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <limits>
#include <ctime>
#include <iomanip>
#include <string>

class NumberAnalyzer {
private:
    std::vector<float> numbers;
    std::string logFile = "program.log";
    
    void logMessage(const std::string& message) {
        std::ofstream log(logFile, std::ios::app);
        time_t now = time(nullptr);
        log << std::put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << ": " << message << "\n";
    }

    void displayHeader() {
        std::cout << "\n*************************************************\n";
        std::cout << "*     Number Analysis Program - Version 2.0      *\n";
        std::cout << "*************************************************\n\n";
    }

    bool saveToFile(float result) {
        try {
            std::ofstream file("results.txt", std::ios::app);
            if (!file) return false;
            file << "Average: " << calculateAverage() << ", Closest number: " << result << "\n";
            return true;
        } catch (...) {
            logMessage("Error saving to file");
            return false;
        }
    }

    float calculateAverage() {
        float sum = 0;
        for (float num : numbers) sum += num;
        return sum / numbers.size();
    }

public:
    bool inputNumbers() {
        displayHeader();
        std::cout << "Enter 5 numbers (press Enter after each):\n";
        
        numbers.clear();
        for (int i = 0; i < 5; i++) {
            float num;
            std::cout << "Number " << (i + 1) << ": ";
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                logMessage("Invalid input detected");
                return false;
            }
            numbers.push_back(num);
        }
        return true;
    }

    float findClosestNumber() {
        float average = calculateAverage();
        float minVariation = std::numeric_limits<float>::max();
        float closest = numbers[0];

        for (float num : numbers) {
            float variation = std::abs(num - average);
            if (variation < minVariation) {
                minVariation = variation;
                closest = num;
            }
        }

        saveToFile(closest);
        return closest;
    }

    void displayResults(float closest) {
        std::cout << "\nResults:\n";
        std::cout << "-------------------------\n";
        std::cout << "Average: " << calculateAverage() << "\n";
        std::cout << "Closest number: " << closest << "\n";
        std::cout << "-------------------------\n";
    }
};

int main() {
    NumberAnalyzer analyzer;
    
    while (true) {
        if (!analyzer.inputNumbers()) {
            std::cout << "Invalid input! Please enter numeric values only.\n";
            continue;
        }

        float closestNumber = analyzer.findClosestNumber();
        analyzer.displayResults(closestNumber);

        std::cout << "\nWould you like to try again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') break;
    }

    return 0;
}
