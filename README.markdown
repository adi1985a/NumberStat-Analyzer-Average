# 📊🔢 NumberStat Analyzer: Average & Closest Value Finder 🎯
_A C++ console application for analyzing a set of five user-input numbers, calculating their average, and identifying the number closest to that average, with results and error logging._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure & Data Persistence](#-file-structure--data-persistence)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**NumberStat Analyzer**, developed by Adrian Lesniak, is a focused C++ console application designed to perform a simple yet insightful statistical analysis on a small dataset of five user-input numbers. The program calculates the arithmetic mean (average) of these numbers and then identifies which of the input numbers is closest to this calculated average. Key results (average and closest number) are saved to `results.txt`, and any operational errors or invalid inputs are logged with timestamps to `program.log`. The application features a user-friendly, interactive interface with robust input validation and a clear display of results, allowing users to retry the analysis with new sets of numbers.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🎯 **Core Analysis (via `NumberAnalyzer` Class)**:
    *   `inputNumbers`: Collects five floating-point numbers from the user, with built-in validation to ensure numeric input.
    *   `calculateAverage`: Computes the arithmetic mean of the five entered numbers.
    *   `findClosestNumber`: Determines which of the input numbers has the smallest absolute difference from the calculated average.
    *   `displayResults`: Clearly presents the calculated average and the identified closest number to the user on the console.
*   💾 **Data Persistence & Logging**:
    *   `saveToFile`: Appends the calculated average and closest number for each successful analysis to `results.txt`.
    *   `logMessage`: Logs errors (e.g., invalid input, file I/O issues) with timestamps to `program.log`.
*   🖥️ **User-Friendly Interface**:
    *   `displayHeader`: Shows the program title and version at startup.
    *   Clear prompts for entering the five numbers.
    *   Option to retry the analysis with a new set of numbers (`y`/`n`).
*   ✔️ **Robust Error Handling**:
    *   Validates that user input is numeric; clears invalid entries and prompts for re-entry.
    *   Logs file I/O errors and invalid input attempts.
*   🔄 **Retry Functionality**: The main program loops, allowing the user to perform multiple analyses in a single session until they choose to exit.

## 🖼️ Screenshots


_Screenshots showcasing the input process, the display of the average and closest number, the retry prompt, and examples from `results.txt` and `program.log`._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
</p>

## ⚙️ System Requirements

*   **Operating System**: Any OS supporting a C++11 (or later) compiler (e.g., Windows, Linux, macOS).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, clang++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<iomanip>`, `<cmath>`, `<vector>`, `<fstream>`, `<string>`, `<limits>`, `<ctime>`, `<numeric>` (for `std::accumulate` if used for average), `<algorithm>` (for `std::min_element` or similar if used for closest).
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `results.txt` and `program.log`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    *(Replace `<repository-url>` and `<repository-directory>` with your specific details)*

2.  **Save Main Code**:
    Ensure your main program logic (including the `NumberAnalyzer` class definition and implementation, and the `main()` function) is saved as `number_analyzer.cpp` (or your chosen main file name) in the project directory. *(The description implies a single-file structure for this project).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++:**
    ```bash
    g++ number_analyzer.cpp -o number_analyzer -std=c++11
    ```
    *(Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables. Add optimization flags like `-O2` for release builds if needed).*

4.  **Run the Program**:
    *   On Windows: `.\number_analyzer.exe` or `number_analyzer.exe`
    *   On Linux/macOS: `./number_analyzer` (ensure execute permissions: `chmod +x number_analyzer`)

## 💡 Usage Guide

1.  Compile and run `number_analyzer` as detailed above.
2.  **Interface & Input**:
    *   The program will display a header with its title and version.
    *   You will be prompted to enter five numbers, one at a time. Press Enter after each number.
    *   If you enter non-numeric input (e.g., letters), an error message will be displayed (and logged), and you will be prompted to re-enter that specific number.
3.  **Output**:
    *   **Console Display**: Once five valid numbers are entered, the program will display:
        *   The calculated average of the numbers (e.g., "Average: 10.00").
        *   The number from your input set that is closest to this average (e.g., "Closest number to average: 9.50").
    *   **`results.txt`**: The calculated average and closest number are appended to this file for each successful analysis session.
    *   **`program.log`**: Any errors encountered (like invalid input attempts or file I/O issues) are logged here with timestamps.
4.  **Retry or Exit**:
    *   After displaying the results, the program will ask if you want to perform another analysis: "Try again? (y/n): ".
    *   Enter `y` (or `Y`) to input a new set of five numbers.
    *   Enter any other key (typically `n` or `N`) to exit the application.

## 🗂️ File Structure & Data Persistence

*   `number_analyzer.cpp`: The main (and likely only) C++ source file containing all program logic, including the `NumberAnalyzer` class definition and implementation, and the `main()` function.
*   `results.txt`: A plain text file where the average and closest number for each set of analyzed inputs are recorded. This file is created or appended to.
*   `program.log`: A plain text file used for logging errors encountered during program execution, with timestamps. This file is created or appended to.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **`NumberAnalyzer` Class**: This class encapsulates the core functionality: storing numbers (likely in a `std::vector<float>` or `std::vector<double>`), handling input, performing calculations (average, closest number), displaying results, and managing file I/O for results and logging.
*   **Input Validation**: Robust input validation using C++ stream states (`std::cin.fail()`, `clear()`, `ignore()`) is implemented to ensure only numeric values are accepted for analysis.
*   **File I/O Error Handling**: The program attempts to handle file I/O errors (e.g., inability to open `results.txt` or `program.log`) by logging the error, but aims to continue operation if possible (e.g., by not crashing if a log file can't be written to, though saving results might be critical).
*   **Cross-Platform Design**: The program is designed to be cross-platform as it relies primarily on standard C++ libraries. Console interaction is standard, and no platform-specific graphics or advanced console manipulation calls are indicated beyond basic text output and standard error streams.
*   **Locale Settings**: No specific locale settings are used; the program uses English text for output and expects standard decimal separators for numbers.
*   **Potential Enhancements**: The application could be extended by:
    *   Allowing a variable number of inputs instead of a fixed five.
    *   Calculating more statistics (e.g., median, mode, standard deviation, range).
    *   Adding options to load numbers from a file.
    *   Implementing a graphical user interface (GUI).

## 🤝 Contributing

Contributions to **NumberStat Analyzer** are highly encouraged! If you have ideas for adding more statistical functions, improving the user interface, enhancing file handling, or optimizing calculations:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourStatEnhancement`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourStatEnhancement'`).
4.  Push to the branch (`git push origin feature/YourStatEnhancement`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🎯 _Finding clarity in numbers, one average at a time._



