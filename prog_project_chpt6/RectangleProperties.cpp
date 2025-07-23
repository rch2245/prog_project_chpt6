// Analysis and Design - RECTANGLE PROPERTIES

// Types of Input:
// User-supplied input:
//   length (double > 0)
//   width (double > 0)
//   continue? (char: Y/N)

// Program Output:
//   perimeter and area of the rectangle

// Processing (Calculations):
//   Validate length > 0
//   Validate width > 0
//   Calculate perimeter = 2 * (length + width)
//   Calculate area = length * width
//   Display results
//   Ask user if they want to process another rectangle

// Tasks:
// 1. Get and validate the length and width of the rectangle from interactive input.
// 2. Calculate the perimeter of the rectangle.
// 3. Calculate the area of the rectangle.
// 4. Display the perimeter and area.
// 5. Repeat if directed to do so by the user.

// Hierarchy Chart:
// main()
//   getLength_Width(length, width)
//   calcPerimeter(length, width) ? perimeter
//   calcArea(length, width) ? area
//   displayProperties(perimeter, area)

// Pseudocode:
// Repeat
//     Call getLength_Width(length, width)
//     perimeter = calcPerimeter(length, width)
//     area = calcArea(length, width)
//     Call displayProperties(perimeter, area)
//     Ask user if they want to process another rectangle
// Until user chooses to quit

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype> // for toupper

// Function Prototypes
void getLength_Width(double& length, double& width);
double calcPerimeter(double length, double width);
double calcArea(double length, double width);
void displayProperties(double perimeter, double area);

void runRectangleProperties() {
    double length = 0.0, width = 0.0;
    double perimeter = 0.0, area = 0.0;
    char choice;

    std::cout << "\nRECTANGLE PROPERTIES PROGRAM\n\n";
    std::cout << "This program calculates the perimeter and area of a rectangle.\n";

    do {
        getLength_Width(length, width);
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);
        displayProperties(perimeter, area);

        std::cout << "\nDo you want to process another rectangle? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (std::toupper(choice) == 'Y');

    std::cout << "\nThank you for using the Rectangle Properties Program!\n";
    return;
}

void getLength_Width(double& length, double& width) {
    std::cout << "\nEnter rectangle length (> 0): ";
    while (!(std::cin >> length) || length <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid number. Please enter a positive value for the  length: ";
    }

    std::cout << "Enter rectangle width (> 0): ";
    while (!(std::cin >> width) || width <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid number. Please enter a positive value for the width: ";
    }
}

double calcPerimeter(double length, double width) {
    return 2 * (length + width);
}

double calcArea(double length, double width) {
    return length * width;
}

void displayProperties(double perimeter, double area) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nRectangle Properties:\n";
    std::cout << "Perimeter: " << perimeter << "\n";
    std::cout << "Area: " << area << "\n";
}
