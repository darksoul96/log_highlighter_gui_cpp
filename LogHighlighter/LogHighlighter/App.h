#include "ui/LogWindow.h"
#include <string>
#ifndef App_h
#define App_h


class App {
   
public:
    void Run(const LogInformation& log_information);

private:
    struct GLFWwindow* m_Window = nullptr;
    LogWindow m_LogWindow;
    void Init();
    void Cleanup();
    void RenderFrame();
};


#endif
