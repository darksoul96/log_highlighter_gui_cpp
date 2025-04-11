//
//  FileManagement.cpp
//  LogHighlighter
//
//  Created by WSO2 on 11/04/2025.
//

#include "FileManagement.hpp"
#include <fstream>
#include <assert.h>
#include <iostream>


size_t FileManagement::CountFileLines(const std::string& filepath) {
    std::ifstream file(filepath);
    assert(file.is_open());

    size_t count = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++count;
    }
    
    file.close();
    return count;
}


void FileManagement::ReadFile(const std::string &filepath, std::vector<std::string>& logLines) {
    std::cout << filepath << std::endl;
    std::vector<std::string> lines;
    std::ifstream file(filepath);
    
    assert(file.is_open());
    std::string line;
    while (std::getline(file, line)) {
        logLines.emplace_back(line);
    }
    file.close();
}

