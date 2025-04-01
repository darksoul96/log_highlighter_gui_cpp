#include <vector>
#include <string>

#ifndef LogWindow_h
#define LogWindow_h

struct LogInformation {
    std::string title;
    std::vector<std::string> log_lines;
};

class LogWindow {
    
public:

    void Create(const LogInformation& log_information);
    
private:
};


#endif /* LogWindow_h */
