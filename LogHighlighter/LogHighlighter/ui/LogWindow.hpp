#include <vector>
#include <string>

#ifndef LogWindow_hpp
#define LogWindow_hpp

struct LogInformation {
    std::string title;
    std::vector<std::string> logLines;
};

class LogWindow {
    
public:
    void Create(const LogInformation& logInformation);
    
private:
};


#endif /* LogWindow_hpp */
