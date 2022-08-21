#include <type_traits>
#include <iostream>
#include <string>

template<typename T>
void linePrinter(T const& t) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "nums: " << t << '\n';
    } else if constexpr (std::is_floating_point_v<T>) {
        const auto frac = t - static_cast<long>(t);
        std::cout << t << ", frac: " << frac << '\n';
    } else if constexpr (std::is_pointer_v<T>) {
        std::cout << "ptr: ";
        linePrinter(*t);
    } else {
        std::cout << t << '\n';
    }
}

template<typename ... Args>
void printWithInfo(Args ... args) {
    (linePrinter(args), ...); // fold expression over the comma operator
}

int main()
{
    int a = 10;
    double d = 10.4;

    float *f = new float(10.5f);

    using namespace std::literals::string_literals;
    std::string name = "Quan"s;

    printWithInfo(a, d, f, name, "Nguyen Mai Trang");

    return 0;
}