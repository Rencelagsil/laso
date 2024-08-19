#include <iostream>
#include <vector>

int main() {
    int numSubjects;
    std::vector<double> grades;
    double total = 0.0;
    double average;

    // Ask for the number of subjects
    std::cout << "Enter the number of subjects: ";
    std::cin >> numSubjects;

    // Ensure numSubjects is a positive number
    if (numSubjects <= 0) {
        std::cout << "Number of subjects must be a positive integer." << std::endl;
        return 1; // Exit with an error code
    }

    // Input grades for each subject
    for (int i = 0; i < numSubjects; ++i) {
        double grade;
        std::cout << "Enter the grade for subject " << (i + 1) << ": ";
        std::cin >> grade;

        // Validate grade input
        if (grade < 0.0 || grade > 100.0) {
            std::cout << "Invalid grade. Please enter a grade between 0 and 100." << std::endl;
            --i; // Re-prompt for the same subject
            continue;
        }

        grades.push_back(grade);
        total += grade;
    }

    // Calculate the average
    average = total / numSubjects;

    // Output the average
    std::cout << "The average grade is: " << average << std::endl;

    return 0; // Successful completion
}


