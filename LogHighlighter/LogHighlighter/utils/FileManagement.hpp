
#include <stdio.h>
#include <string>
#include <vector>
#include "../imgui/imgui.h"

#ifndef FileManagement_hpp
#define FileManagement_hpp




struct ParsedTextColored {
    std::string text;
    ImU32 color;
};

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
    
    std::vector<HighlightRule> LoadLineRules(const std::string& rulesFilepath);

    std::vector<ParsedTextColored> ParseLogFile(const std::string& filepath, const size_t fileSize, const std::vector<HighlightRule>& rules);

}

#endif /* FileManagement_hpp */
