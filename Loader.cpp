#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#include <chrono>
#endif

//This programm is for loading saves

void Loader(Character& hero, MyInventory& inv)
{
    std::cout << "Enter save filename to load (e.g. MySave): ";
    std::string name;
    std::getline(std::cin, name);

    if (name.empty()) name = "Saves";

    std::string path = name + ".txt";

    std::ifstream fs(path);
    if (!fs.is_open()) {
        std::cout << "Error: cannot open file '" << path << "'\n";
        return;
    }

    std::cout << "=== SAVES ===" << std::endl;
        std::cout << "";
        std::string str;
        while(!fs.eof())
        {
            str= " ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, name);
            std::cout << str << std::endl;
        }
}