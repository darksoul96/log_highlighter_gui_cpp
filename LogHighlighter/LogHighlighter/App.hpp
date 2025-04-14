#include "ui/LogWindow.hpp"
#include <string>
#include "utils/TimerBenchmark.hpp"
#include "utils/FileManagement.hpp"

#ifndef App_hpp
#define App_hpp

class App {
   
public:
    LogInformation m_logInformation;
    std::vector<HighlightRule> m_highlightRules;
    bool Initialize(int , char**);
    void Run();

private:
    struct GLFWwindow* m_Window = nullptr;
    LogWindow m_LogWindow;
    void InitWindow();
    void Cleanup();
    void RenderFrame();
};


#endif
