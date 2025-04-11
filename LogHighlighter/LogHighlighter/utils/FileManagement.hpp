#ifndef FileManagement_hpp
#define FileManagement_hpp

#include <stdio.h>
#include <string>
#include <vector>

namespace FileManagement {
    size_t CountFileLines(const std::string& filepath);
    
    void ReadFile(const std::string &filepath, std::vector<std::string>& logLines);

    

}

#endif /* FileManagement_hpp */
