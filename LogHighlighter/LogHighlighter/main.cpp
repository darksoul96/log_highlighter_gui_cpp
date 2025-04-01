#include <iostream>
#include "app.h"
#include <GLFW/glfw3.h>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <cassert>
#include <chrono>


class Timer {

public:
    Timer() {
        m_StartTime = std::chrono::high_resolution_clock::now();
    }
    
    ~Timer() {
        auto endTime = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTime).time_since_epoch();
        
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch();
        auto duration = end - start;
        auto duration_miliseconds = duration * 0.001;
        
        std::cout << duration << " microseconds" << std::endl;
        std::cout << duration_miliseconds << " miliseconds" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
};


size_t CountFileLines(const std::string& filepath) {
    std::ifstream file(filepath);
    assert(file.is_open());

    size_t count = 0;
    std::string line;
    while (std::getline(file, line)) {
        ++count;
    }
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

// Main code
int main(int, char**)
{
    /*{
        Timer timer;
    }*/
    
    std::string filepath = "/Users/wso2/Desktop/wso2carbon.log";
    size_t filesize = CountFileLines(filepath);
    
    LogInformation log_information;
    log_information.title = "Log";
    log_information.log_lines.reserve(filesize);
    //log_information.log_lines.reserve(10000);
    
    ReadFile(filepath, log_information.log_lines);
    App app;
    app.Run(log_information);

    return 0;
}
