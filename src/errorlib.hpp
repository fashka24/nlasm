#pragma once

#define FAILWITH_RED 0
#define FAILWITH_DEFUALT 1

namespace std {
    void failwith(std::string message, int index) {
        if (index == 0) {
            std::cout << "\u001b[31m" << message << endl;
            exit(1);
        }
        else if (index == 1) {
            std::cout << message << endl;
            exit(1);
        }
    }
}