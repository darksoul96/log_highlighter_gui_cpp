#include "ui/LogWindow.hpp"
#include <string>
#ifndef App_hpp
#define App_hpp

class App {
   
public:
    void Run(const LogInformation& logInformation);

private:
    struct GLFWwindow* m_Window = nullptr;
    LogWindow m_LogWindow;
    void Init();
    void Cleanup();
    void RenderFrame();
};


#endif
