// Analysis and Design - STAR SEARCH

// Types of Input:
//   Five scores from judges (double between 0.0 and 10.0)

// Program Output:
//   Final score calculated by dropping highest and lowest, averaging the remaining three

// Processing (Calculations):
//   Validate each score (0–10)
//   Keep track of total, min score, and max score
//   Compute average = (total - minScore - maxScore) / 3

// Tasks:
// 1. Get and validate each judge's score
// 2. Track total, minimum, and maximum score
// 3. Calculate final average by excluding highest and lowest score
// 4. Display result

// Hierarchy Chart:
// main()
//   ─ getScore() → double
//   ─ isLower(a, b) → bool
//   ─ isHigher(a, b) → bool
//   ─ calcAverage(total, minScore, maxScore) → double

// Pseudocode:
// Initialize total = 0, read first score
// Set minScore = maxScore = first score
// For remaining 4 judges:
//   score = getScore()
//   Add score to total
//   If score < minScore → update minScore
//   If score > maxScore → update maxScore
// After loop:
// finalAverage = calcAverage(total, minScore, maxScore)
// Display finalAverage

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <limits>


// Function Prototypes
double getScore(int judgeNumber);
bool isLower(double a, double b);
bool isHigher(double a, double b);
double calcAverage(double total, double minScore, double maxScore);

void runStarSearch() {
    const int NUM_JUDGES = 5;
    double score = 0.0, total = 0.0;
    double minScore = 0.0, maxScore = 0.0;

    std::cout << "\nSTAR SEARCH PROGRAM\n\n";
    std::cout << "Enter scores for " << NUM_JUDGES << " judges (0.0 to 10.0):\n";

    // First score initializes min and max
    score = getScore(1); // Judge #1
    total = score;
    minScore = score;
    maxScore = score;

    // Process remaining scores
    for (int i = 2; i <= NUM_JUDGES; i++) {
        score = getScore(i); // Judge #i
        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        }
        if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    double finalAverage = calcAverage(total, minScore, maxScore);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nFinal Score (after dropping highest and lowest): " << finalAverage << "\n";
}

// Updated getScore to take judgeNumber as input
double getScore(int judgeNumber) {
    double score;
    std::cout << "Enter score for Judge #" << judgeNumber << " (0 to 10): ";
    while (!(std::cin >> score) || score < 0.0 || score > 10.0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a score between 0 and 10: ";
    }
    return score;
}

bool isLower(double a, double b) {
    return a <= b;
}

bool isHigher(double a, double b) {
    return a >= b;
}

double calcAverage(double total, double minScore, double maxScore) {
    return (total - minScore - maxScore) / 3.0;
}
