#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <filesystem>

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


void Deleter()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    ListSaveFiles();
    
    std::cout << "\nEnter save number to delete it ";
    std::string num_delete_save;
    std::getline(std::cin, num_delete_save);
    
    if (num_delete_save.empty()) {
        num_delete_save = "Saves";
    }

    std::string path = num_delete_save; + ".txt";
    std::ofstream fs(path);
    
    Fail_To_Open_File(fs);

    std::error_code ec;    
    if (std::filesystem::remove(num_delete_save, ec)) {
        std::cout << "File deleted successfully!\n";
    } else {
        std::cout << "Error to delete file " << ec.message() << '\n';
    }

    fs.close();
    Fail_To_Close_File(fs);
    Check_Save_Status(fs, path);

}