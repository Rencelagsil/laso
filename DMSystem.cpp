#include <iostream>
#include <direct.h>  // For _mkdir, _chdir
#include <filesystem> // For file listing and directory operations
#include <string>
#include <vector>

namespace fs = std::filesystem;

void displayMenu();
void listFiles();
void createDirectory();
void changeDirectory();
void listAllFiles(const fs::path& path);
void listFilesByExtension(const fs::path& path, const std::string& extension);
void listFilesByPattern(const fs::path& path, const std::string& pattern);

int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the input buffer
        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createDirectory();
                break;
            case 3:
                changeDirectory();
                break;
            case 4:
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "Directory Management System\n";
    std::cout << "1. List Files\n";
    std::cout << "2. Create Directory\n";
    std::cout << "3. Change Directory\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void listFiles() {
    int choice;
    fs::path currentPath = fs::current_path();

    std::cout << "List Files Menu:\n";
    std::cout << "1. List all files\n";
    std::cout << "2. List files by extension\n";
    std::cout << "3. List files by pattern\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            listAllFiles(currentPath);
            break;
        case 2: {
            std::string extension;
            std::cout << "Enter file extension (e.g., .txt): ";
            std::getline(std::cin, extension);
            listFilesByExtension(currentPath, extension);
            break;
        }
        case 3: {
            std::string pattern;
            std::cout << "Enter file pattern (e.g., moha*.*): ";
            std::getline(std::cin, pattern);
            listFilesByPattern(currentPath, pattern);
            break;
        }
        default:
            std::cout << "Invalid choice. Returning to main menu." << std::endl;
    }
}

void listAllFiles(const fs::path& path) {
    std::cout << "Listing all files in: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void listFilesByExtension(const fs::path& path, const std::string& extension) {
    std::cout << "Listing files with extension " << extension << " in: " << path << std::endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            std::cout << entry.path().filename() << std::endl;
        }
    }
}

void listFilesByPattern(const fs::path& path, const std::string& pattern) {
    // This requires implementing a custom pattern matching function
    // Basic implementation might use regex
    std::cout << "Pattern matching is not implemented yet." << std::endl;
}

void createDirectory() {
    std::string dirName;
    std::cout << "Enter the directory name: ";
    std::getline(std::cin, dirName);

    if (_mkdir(dirName.c_str()) == 0) {
        std::cout << "Directory created successfully: " << dirName << std::endl;
    } else {
        std::perror("Error creating directory");
    }
}

void changeDirectory() {
    int choice;
    std::cout << "Change Directory Menu:\n";
    std::cout << "1. Move to parent directory\n";
    std::cout << "2. Move to root directory\n";
    std::cout << "3. Move to specific directory\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1:
            if (_chdir("..") == 0) {
                std::cout << "Moved to parent directory.\n";
            } else {
                std::perror("Error moving to parent directory");
            }
            break;
        case 2:
            if (_chdir("\\") == 0) {
                std::cout << "Moved to root directory.\n";
            } else {
                std::perror("Error moving to root directory");
            }
            break;
        case 3: {
            std::string path;
            std::cout << "Enter the directory path: ";
            std::getline(std::cin, path);
            if (_chdir(path.c_str()) == 0) {
                std::cout << "Moved to directory: " << path << std::endl;
            } else {
                std::perror("Error moving to specified directory");
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Returning to main menu." << std::endl;
    }
}




