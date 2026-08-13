#include "Header.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Для ifstream (чтения)
void Fail_To_Close_File(std::ifstream& fs) {
    fs.close();
    if (fs.is_open()) {
        std::cout << "Error! File is still open" << std::endl;
    }
}

void Fail_To_Open_File(std::ifstream& fs) {
    if (!fs.is_open()) {
        std::cout << "Error: failed to open load file!\n";
        throw std::runtime_error("Failed to open file");
    }
}

// Для ofstream (записи)
void Fail_To_Close_File(std::ofstream& fs) {
    fs.close();
    if (fs.is_open()) {
        std::cout << "Error! File is still open" << std::endl;
    }
}

void Fail_To_Open_File(std::ofstream& fs) {
    if (!fs.is_open()) {
        std::cout << "Error: failed to open load file!\n";
        throw std::runtime_error("Failed to open file");
    }
}

void File_Is_Empty(std::ofstream& fs) {
    if (fs.is_open()) {
        std::streampos currentPos = fs.tellp();
        fs.seekp(0, std::ios::end);
        
        if (fs.tellp() == 0) {
            std::cout << "Error: File is empty!" << std::endl;
        }
        
        fs.seekp(currentPos);
    }
}

std::string Check_Save_Status(std::ofstream& fs, std::string path) {
    fs.close();
    if (fs.is_open()) {
        std::cout << "Error! File is still open" << std::endl;
        return "error";
    }
    std::cout << "\nGame saved successfully to '" << path << "'!\n";
    return "success";
}