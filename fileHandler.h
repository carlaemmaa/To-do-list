#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>

class FileHandler {
public:
    void writeToFile(const std::vector<std::string>& tasks, const std::vector<bool>& completed);
    void readFromFile(std::vector<std::string>& tasks, std::vector<bool>& completed);
};

#endif
