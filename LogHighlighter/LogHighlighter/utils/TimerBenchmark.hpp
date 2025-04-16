#include <iostream>
#include <chrono>
#ifndef TimerBenchmark_hpp
#define TimerBenchmark_hpp

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
        
        std::cout << duration.count() << " microseconds" << std::endl;
        std::cout << duration_miliseconds.count() << " miliseconds" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
};
#endif /* TimerBenchmark_hpp */
