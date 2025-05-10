# Number Analysis Program

## Overview
This C++ console application analyzes five user-input numbers, calculating their average and identifying the number closest to it. Results are saved to `results.txt`, errors are logged to `program.log`, and the program supports retrying with input validation and a user-friendly interface.

## Features
- **NumberAnalyzer Class**:
  - Stores numbers in a `std::vector<float>`.
  - `inputNumbers`: Collects five numbers with validation.
  - `calculateAverage`: Computes the mean of input numbers.
  - `findClosestNumber`: Finds the number with minimal deviation from the average.
  - `displayResults`: Shows average and closest number.
  - `saveToFile`: Appends results to `results.txt`.
  - `logMessage`: Logs errors with timestamps to `program.log`.
- **Interface**:
  - `displayHeader`: Shows program title and version.
  - Prompts for five numbers and retry option (y/n).
- **Error Handling**:
  - Validates numeric input, clears invalid entries.
  - Logs file I/O errors and invalid inputs.
- **Main Program**:
  - Loops to allow retrying until user exits.
  - Displays results and saves them to file.

## Requirements
- C++ compiler (e.g., g++, clang++) with C++11 or later
- Standard C++ libraries: `<iostream>`, `<cmath>`, `<vector>`, `<fstream>`, `<limits>`, `<ctime>`, `<iomanip>`, `<string>`
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)
- Write permissions for `results.txt` and `program.log`

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `number_analyzer.cpp`.
3. Compile the program:
   ```bash
   g++ number_analyzer.cpp -o number_analyzer
   ```
4. Run the program:
   ```bash
   ./number_analyzer
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header and prompts for five numbers.
   - Shows results: average and closest number.
   - Asks to retry (y/n).
3. **Input**:
   - Enter five numbers, one per prompt.
   - Invalid inputs (e.g., letters) trigger an error and retry.
4. **Output**:
   - Console: Average and closest number (e.g., "Average: 10, Closest number: 9.5").
   - `results.txt`: Appends results (e.g., "Average: 10, Closest number: 9.5").
   - `program.log`: Logs errors with timestamps (e.g., invalid input).
5. **Actions**:
   - Enter 'y' to retry, any other key to exit.

## File Structure
- `number_analyzer.cpp`: Main C++ source file with program logic.
- `results.txt`: Output file for results (created/appended).
- `program.log`: Log file for errors (created/appended).
- `README.md`: This file, providing project documentation.

## Notes
- No locale settings; uses English text for output.
- Input validation ensures only numeric values are accepted.
- File I/O errors are logged but do not crash the program.
- Extend by adding more statistics (e.g., median, standard deviation) or GUI support.
- Ensure write permissions for `results.txt` and `program.log`.
- No external dependencies; uses only standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.