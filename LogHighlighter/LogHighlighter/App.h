#include "ui/LogWindow.h"

#ifndef App_h
#define App_h


class App {
   
public:

    void Run();

private:
    struct GLFWwindow* m_Window = nullptr;
    LogWindow m_LogWindow;
    void Init();
    void Cleanup();
    void RenderFrame();
};


#endif
