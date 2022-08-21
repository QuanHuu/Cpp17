#include <iostream>

int main()
{
    register int a = 10; // The register keyword is not allowed using in C++17

    // this will throw a warning

    std::cout << &a << ": " << a << '\n';

    return 0;
}