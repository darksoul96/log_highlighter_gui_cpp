#include <vector>
#include <string>
#include "../imgui/imgui.h"
#include "../utils/FileManagement.hpp"

struct LogInformation {
    std::string title;
    std::vector<std::string> logLines;
};

#ifndef LogWindow_hpp
#define LogWindow_hpp



class LogWindow {
    
public:
    void Create(const LogInformation& logInformation, const std::vector<HighlightRule>& m_highlightRules);
    
private:
    
};


#endif /* LogWindow_hpp */
