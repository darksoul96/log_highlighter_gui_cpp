#include <iostream>
#include "app.h"
#include <GLFW/glfw3.h>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <cassert>
#include <chrono>
#include "utils/TimerBenchmark.h"


size_t CountFileLines(const std::string& filepath) {
    std::ifstream file(filepath);
    assert(file.is_open());

    size_t count = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++count;
    }
    
    file.close();
    return count;
}


void ReadFile(const std::string &filepath, std::vector<std::string>& log_lines) {
    std::cout << filepath << std::endl;
    std::vector<std::string> lines;
    std::ifstream file(filepath);
    
    assert(file.is_open());
    std::string line;
    while (std::getline(file, line)) {
        log_lines.emplace_back(line);
    }
    file.close();
}

int main(int argc, char** argv)
{
    /*{
        Timer timer;
        
    }*/
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-log-file>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    
    size_t filesize = CountFileLines(filepath);
    
    LogInformation log_information;
    log_information.title = "Log";
    log_information.log_lines.reserve(filesize);
    
    ReadFile(filepath, log_information.log_lines);
    App app;
    app.Run(log_information);

    return 0;
}
