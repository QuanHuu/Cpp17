#include <iostream>

int main() {
    bool ret = false;
    ++ret; // you cannot can operator++ in bool data type from C++17

    if (ret) {
        std::cout << "Can printing\n";
    }

    return 0;
}