#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

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
            std::cout << "│  " << (++count) << ". " << findFileData.cFileName << "\n";
            found = true;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);
    
    FindClose(hFind);

    if (!found) {
        std::cout << "│  No saves found.                                  │\n";
    }
    
    std::cout << "└───────────────────────────────────────────────────┘\n";
}