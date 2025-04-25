#include "FileManagement.hpp"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <iomanip>


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


std::vector<ParsedTextColored> FileManagement::ParseLogFile(const std::string& filepath, const size_t fileSize, const std::vector<HighlightRule>& rules) {
    std::ifstream file(filepath);

    assert(file.is_open());

    std::vector<ParsedTextColored> parsedText;
    parsedText.reserve(fileSize);
    std::string line;

    size_t line_number = 0;
    while (std::getline(file, line)) {
        ParsedTextColored newParsedLine;
        newParsedLine.index = line_number;
        newParsedLine.text = line;
        newParsedLine.color = 0xFFFFFFFF; 
        for (const auto& rule : rules) {
            if (line.find(rule.PatternRule) != std::string::npos) {
                newParsedLine.color = rule.ColorRule;
                break;
            }
        }

        line_number++;
        parsedText.push_back(newParsedLine);
    }

    file.close();

    return parsedText;
}


