#include <iostream>
#include "App.hpp"
#include <GLFW/glfw3.h>
#include "utils/TimerBenchmark.hpp"
#include "utils/FileManagement.hpp"



int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-log-file>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    size_t filesize =  FileManagement::CountFileLines(filepath);
    
    LogInformation logInformation;
    logInformation.title = "Log";
    logInformation.logLines.reserve(filesize);
    
    FileManagement::ReadFile(filepath, logInformation.logLines);
    App app;
    app.Run(logInformation);

    return 0;
}
