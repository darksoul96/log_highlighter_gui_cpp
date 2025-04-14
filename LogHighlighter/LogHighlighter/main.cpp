#include "App.hpp"

int main(int argc, char** argv)
{
    #ifdef NDEBUG
    std::cout << "🚀 Release build\n";
    #else
    std::cout << "🐌 Debug build\n";
    #endif

    App app;
    
    if (!app.Initialize(argc, argv)) {
        return 1;
    }
    
    app.Run();

    return 0;
}
