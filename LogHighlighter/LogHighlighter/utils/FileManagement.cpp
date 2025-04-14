#include "FileManagement.hpp"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>


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


std::vector<HighlightRule> FileManagement::LoadLineRules(const std::string& rulesFilepath) {
    std::ifstream file(rulesFilepath);
    
    std::vector<HighlightRule> ruleLines;
    ruleLines.reserve(6);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Failed to open rules file!" << std::endl;
        return ruleLines;
    }
    

    while (std::getline(file, line)) {
        std::istringstream inputStringStream(line);
        std::string pattern;
        unsigned int r, g, b, alpha;
        
        if (!(inputStringStream >> std::quoted(pattern) >> r >> g >> b >> alpha)) {
            continue; // skip malformed lines
        }
        
        ruleLines.emplace_back(pattern, r, g, b, alpha);
    }
    file.close();
    
    return ruleLines;
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

