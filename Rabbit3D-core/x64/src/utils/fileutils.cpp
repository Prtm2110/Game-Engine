#include "fileutils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace rabbit {
    namespace utils {
        std::string read_file(const std::string& filepath) {
            std::ifstream file(filepath);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file: " + filepath);
            }

            std::stringstream buffer;
            buffer << file.rdbuf();
            return buffer.str();
        }
    }
}
