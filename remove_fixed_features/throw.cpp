#include <iostream>

void print(bool throwable = false) throw(int) // removed from C++17
{
    if (throwable) {
        throw 1;
    }
}

int main()
{
    try {
        print(true);
    } catch (...) {
        std::cout << "Exception\n";
    }

    return 0;
}