#pragma once
#include "ospch.hpp"

namespace OSLib {
    class Utils {
    public:
        static std::vector<std::string> SplitString(const std::string& _string, char _delimiter) {
            std::vector<std::string> result;
            std::stringstream ss(_string);
            std::string item;

            while (std::getline(ss, item, _delimiter)) {
                result.push_back(item);
            }

            return result;
        }
    };
}