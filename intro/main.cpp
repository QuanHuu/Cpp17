#include <map>
#include <iostream>
#include <string>


int main() {
    using namespace std::literals::string_literals;
    std::map<std::string, int> mappUserAge = {{ "Quan"s, 27 }, { "Trang"s, 25 }};

    std::map otherMap(mappUserAge); // C17 feature

    if (auto [iter, added] = otherMap.insert_or_assign("Quan"s, 28 ); !added) {
        std::cout << iter->first << " Reassigned...\n";
    }

    for (auto const& [name, age] : otherMap) {
        std::cout << name << ": " << age << '\n';
    }

    return 0;
}