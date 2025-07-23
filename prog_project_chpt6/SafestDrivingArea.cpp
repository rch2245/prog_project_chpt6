
// Analysis and Design - SAFEST DRIVING AREA

// Types of Input:
//   User-supplied input:
//     region name (string)
//     number of accidents (int >= 0)

// Program Output:
//   Name of the region with the lowest accidents and its accident count.

// Processing (Calculations):
//   Validate accidents >= 0.
//   For each region (north, south, east, west, central):
//     Prompt for number of accidents.
//     Track the region with the fewest accidents.
//   Display safest region and its accident count.

// Algorithm / Tasks:
// 1. Get and validate accident data for each region.
// 2. Compare accident values and track the lowest.
// 3. Display the region with the fewest accidents.

// Hierarchy Chart:
// main()
//   ─ getRegInfo(regionName, accidentCount)
//   ─ isLower(newValue, currentLowest) → bool
//   ─ showLowest(safestRegionName, lowestAccidentCount)

// Pseudocode:
// Initialize safestRegionName and lowestAccidentCount.
// For each region in [north, south, east, west, central]:
//     Call getRegInfo(regionName, accidentCount)
//     If isLower(accidentCount, lowestAccidentCount):
//         Update safestRegionName and lowestAccidentCount.
// Call showLowest(safestRegionName, lowestAccidentCount).


#include "pch.h"
#include <iostream>
#include <string>
#include <limits>

// Function Prototypes
void getRegInfo(const std::string &regionName, int &accidents);
bool isLower(int newValue, int currentLowest);
void showLowest(const std::string &regionName, int accidents);

void runSafestDrivingArea() {
    std::string regions[] = {"North", "South", "East", "West", "Central"};
    std::string safestRegion;
    int lowestAccidents = std::numeric_limits<int>::max();
    int accidents = 0;

    std::cout << "\nSAFEST DRIVING AREA PROGRAM\n\n";
    std::cout << "This program determines the region with the fewest automobile accidents last year.\n";

    for (const std::string &region : regions) {
        getRegInfo(region, accidents);
        if (isLower(accidents, lowestAccidents)) {
            lowestAccidents = accidents;
            safestRegion = region;
        }
    }

    showLowest(safestRegion, lowestAccidents);
    return;
}

void getRegInfo(const std::string &regionName, int &accidents) {
    std::cout << "Enter the number of accidents reported in the " << regionName << " region: ";
    while (!(std::cin >> accidents) || accidents < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid number. Enter a non-negative number: ";
    }
}

bool isLower(int newValue, int currentLowest) {
    return newValue <= currentLowest;
}

void showLowest(const std::string &regionName, int accidents) {
    std::cout << "\nThe safest driving area is the " << regionName
              << " region with " << accidents << " reported accidents.\n";
}
