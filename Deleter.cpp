#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <filesystem>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#include <chrono>
#endif


inline void ListSaveFiles() {
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                  EXISTING SAVES                   │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA("*.txt", &findFileData);
    
    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "│  No saves found.                                  │\n";
        std::cout << "└───────────────────────────────────────────────────┘\n";
        return;
    }

    bool found = false;
    int count = 0;
    
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::cout << "│  " << (++count) << ". " << findFileData.cFileName << "Delete ?"<<"\n";
            found = true;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);
    
    FindClose(hFind);

    if (!found) {
        std::cout << "│  No saves found.                                  │\n";
    }
    
    std::cout << "└───────────────────────────────────────────────────┘\n";
}


void Deleter() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::vector<std::string> saveFiles;
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA("*.txt", &findFileData);
    
    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "No saves found.\n";
        return;
    }

    int count = 0;
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            saveFiles.push_back(findFileData.cFileName);
            std::cout << ++count << ". " << findFileData.cFileName << "\n";
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);
    FindClose(hFind);

    if (saveFiles.empty()) {
        std::cout << "No saves found.\n";
        return;
    }

    std::cout << "\nEnter save number to delete it: ";
    std::string num_delete_save;
    std::getline(std::cin, num_delete_save);

    if (num_delete_save.empty()) {
        std::cout << "Cancelled.\n";
        return;
    }

    int index = std::stoi(num_delete_save) - 1;
    if (index < 0 || index >= saveFiles.size()) {
        std::cout << "Invalid number!\n";
        return;
    }

    const std::string& filename = saveFiles[index];
    
    std::error_code ec;
    if (std::filesystem::remove(filename, ec)) {
        std::cout << "File '" << filename << "' deleted successfully!\n";
    } else {
        std::cout << "Error deleting file: " << ec.message() << '\n';
    }
}