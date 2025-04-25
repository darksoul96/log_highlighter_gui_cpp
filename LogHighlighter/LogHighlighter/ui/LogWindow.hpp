#include <vector>
#include <string>
#include "../imgui/imgui.h"
#include "../utils/FileManagement.hpp"


#ifndef LogWindow_hpp
#define LogWindow_hpp




class LogWindow {
    
public:
    void Create(const std::vector<ParsedTextColored>& parsedTextList, bool& wrapText, const bool useLightBackground);

    void DrawLine(const ParsedTextColored& line, const bool& wrapText);
    
private:
    
};


#endif /* LogWindow_hpp */
