#include "ui/LogWindow.hpp"
#include <string>
#include "utils/TimerBenchmark.hpp"
#include "utils/FileManagement.hpp"

#ifndef App_hpp
#define App_hpp



class App {
   
public:
    std::vector<HighlightRule> m_highlightRules;
    static bool m_wrapText;
    bool m_useLightColor;
    bool Initialize(int , char**);
    void Run();

private:
    std::vector<ParsedTextColored> m_ParsedTextList;
    struct GLFWwindow* m_Window = nullptr;
    LogWindow m_LogWindow;
    void InitWindow();
    void Cleanup();
    void RenderFrame();
};


#endif
