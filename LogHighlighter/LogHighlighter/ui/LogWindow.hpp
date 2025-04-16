#include <vector>
#include <string>
#include "../imgui/imgui.h"
#include "../utils/FileManagement.hpp"


#ifndef LogWindow_hpp
#define LogWindow_hpp




class LogWindow {
    
public:
    void Create(const std::vector<ParsedTextColored>& parsedTextList, const bool wrapText, const bool useLightBackground);
    
private:
    
};


#endif /* LogWindow_hpp */
