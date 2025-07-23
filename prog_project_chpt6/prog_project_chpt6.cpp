#include "pch.h"
#include <iostream>
#include <limits>
#include <cctype>


#include "RectangleProperties.h"
#include "StarSearch.h"
#include "SafestDrivingArea.h"
#include "CelsiusTemperatureTable.h"
#include "PaintJobEstimator.h"

int main() {
    int choice = 0;

    do {
        std::cout << "\n===== CHAPTER 6 PROJECT MENU =====\n";
        std::cout << "1. Rectangle Properties\n";
        std::cout << "2. Star Search\n";
        std::cout << "3. Safest Driving Area\n";
        std::cout << "4. Celsius Temperature Table\n";
        std::cout << "5. Paint Job Estimator\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter a number 1-6: ";
        }

        switch (choice) {
        case 1:
            runRectangleProperties();
            break;
        case 2:
            runStarSearch();
            break;
        case 3:
            runSafestDrivingArea();
            break;
        case 4:
            runCelsiusTemperatureTable();
            break;
        case 5:
            runPaintJobEstimator();
            break;
        case 6:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
