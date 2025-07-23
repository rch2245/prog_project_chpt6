// Analysis and Design - CELSIUS TEMPERATURE TABLE

// Types of Input:
//   None (program uses a fixed range 0–20 Celsius)

// Program Output:
//   A table of Celsius and Fahrenheit values for 0–20 degrees.

// Processing (Calculations):
//   Use the formula Fahrenheit = (9.0 / 5.0) * Celsius + 32.
//   Display Celsius and Fahrenheit in tabular form with one decimal precision.

// Algorithm / Tasks:
// 1. Define constants MIN_TEMP = 0 and MAX_TEMP = 20.
// 2. Display table header.
// 3. For each Celsius value from MIN_TEMP to MAX_TEMP:
//    - Compute Fahrenheit.
//    - Display Celsius and Fahrenheit formatted.

// Hierarchy Chart:
// main()
//   ─ displayTemperatureTable()

// Pseudocode:
// Define MIN_TEMP = 0, MAX_TEMP = 20
// Call displayTemperatureTable()
// displayTemperatureTable():
// Print header
// For celsius = MIN_TEMP to MAX_TEMP:
//     fahrenheit = (9.0 / 5.0) * celsius + 32
//     Print celsius and fahrenheit

#include <iostream>
#include <iomanip>

const int MIN_TEMP = 0;
const int MAX_TEMP = 20;

// Function prototypes
void displayTemperatureTable();

void runCelsiusTemperatureTable() {
    std::cout << "\nCELSIUS TEMPERATURE TABLE\n\n";
    displayTemperatureTable();
    return;
}

void displayTemperatureTable() {
    std::cout << std::setw(10) << "Celsius" << std::setw(15) << "Fahrenheit" << "\n";
    std::cout << "-----------------------------\n";

    std::cout << std::fixed << std::setprecision(1);
    for (int celsius = MIN_TEMP; celsius <= MAX_TEMP; ++celsius) {
        double fahrenheit = (9.0 / 5.0) * celsius + 32.0;
        std::cout << std::setw(10) << celsius << std::setw(15) << fahrenheit << "\n";
    }
}
