// Analysis and Design - PAINT JOB ESTIMATOR

// Types of Input:
//   User-supplied input:
//     Wall area in square feet (double > 0)
//     Price of paint per gallon (double > 0)

// Program Output:
//   Gallons of paint required, labor hours, cost of paint, labor charges, and total cost.

// Processing (Calculations):
//   1 gallon covers 115 sq ft
//   1 gallon requires 8 labor hours
//   Labor charge = $20 per hour
//   Gallons = ceil(area / 115)
//   Labor hours = gallons * 8
//   Paint cost = gallons * price per gallon
//   Labor cost = labor hours * 20
//   Total cost = paint cost + labor cost

// Algorithm / Tasks:
// 1. Get and validate wall area and paint price.
// 2. Calculate gallons, labor hours, paint cost, labor cost, and total cost.
// 3. Display results.

// Hierarchy Chart:
// main()
//   ─ getInput(area, price)
//   ─ calcValues(area, price, gallons, hours, paintCost, laborCost, totalCost)
//   ─ displayResults(gallons, hours, paintCost, laborCost, totalCost)

// Pseudocode:
// Get area and price using getInput()
// Compute values using calcValues()
// Display results using displayResults()

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

// Function Prototypes
void getInput(double &area, double &price);
void calcValues(double area, double price, int &gallons, double &hours,
                double &paintCost, double &laborCost, double &totalCost);
void displayResults(int gallons, double hours, double paintCost,
                    double laborCost, double totalCost);

const double COVERAGE = 115.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_RATE = 20.0;

void runPaintJobEstimator() {
    double area = 0.0, price = 0.0;
    int gallons = 0;
    double hours = 0.0, paintCost = 0.0, laborCost = 0.0, totalCost = 0.0;

    std::cout << "\nPAINT JOB ESTIMATOR\n\n";
    getInput(area, price);
    calcValues(area, price, gallons, hours, paintCost, laborCost, totalCost);
    displayResults(gallons, hours, paintCost, laborCost, totalCost);

    return;
}

void getInput(double &area, double &price) {
    std::cout << "Enter wall area in square feet: ";
    while (!(std::cin >> area) || area <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "You have entered an invalid number. Please enter a positive number for the area: ";
    }
    std::cout << "Enter price of paint per gallon: ";
    while (!(std::cin >> price) || price <= 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "You have entered an invalid number. Please enter a positive number for the price: ";
    }
}

void calcValues(double area, double price, int &gallons, double &hours,
                double &paintCost, double &laborCost, double &totalCost) {
    gallons = static_cast<int>(std::ceil(area / COVERAGE));
    hours = gallons * HOURS_PER_GALLON;
    paintCost = gallons * price;
    laborCost = hours * LABOR_RATE;
    totalCost = paintCost + laborCost;
}

void displayResults(int gallons, double hours, double paintCost,
                    double laborCost, double totalCost) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nPaint Job Estimate:\n";
    std::cout << "Gallons of paint required: " << gallons << "\n";
    std::cout << "Hours of labor required: " << hours << "\n";
    std::cout << "Cost of paint: $" << paintCost << "\n";
    std::cout << "Labor charges: $" << laborCost << "\n";
    std::cout << "Total cost: $" << totalCost << "\n";
}
