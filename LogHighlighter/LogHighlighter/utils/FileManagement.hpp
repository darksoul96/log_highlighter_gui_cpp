
#include <stdio.h>
#include <string>
#include <vector>
#include "../imgui/imgui.h"

#ifndef FileManagement_hpp
#define FileManagement_hpp



struct HighlightRule {
    std::string PatternRule;
    ImU32 ColorRule;
    
    HighlightRule(const std::string& pattern, const ImU32& color)
    : PatternRule(pattern), ColorRule(color) {}
    
    HighlightRule(const std::string& pattern, unsigned int r, unsigned int g, unsigned int b, unsigned int alpha)
            : PatternRule(pattern), ColorRule(IM_COL32(r, g, b, alpha)) {}
};

namespace FileManagement {

    size_t CountFileLines(const std::string& filepath);
    
    void ReadFile(const std::string &filepath, std::vector<std::string>& logLines);

    std::vector<HighlightRule> LoadLineRules(const std::string& rulesFilepath);

}

#endif /* FileManagement_hpp */
