#include <iostream>
#include "fast_hashmap.hpp"

int main(void)
{
    std::cout << "Fast-hashmap." << std::endl;
    chronicode::fast_hashmap<int, int> m;
    m.insert(69, 10);
    m.get(69);
    m.erase(69);
    return 0;
}