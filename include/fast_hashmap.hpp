#include <cstddef>
#include <iostream>
#include <vector>

namespace chronicode
{

template <typename T, typename F>
class fast_hashmap
{
private:
    using Key = T;
    using Val = F;
    using Buckets = std::vector<Val>;
public:

    fast_hashmap(std::size_t sz) : load_factor{2}, buckets(sz * load_factor) {}
    fast_hashmap() : fast_hashmap(1024) {}

    bool insert(const Key &k, Val v)
    {
        std::cout << "insert!\n";
        return true;
    }

    Val& get(const Key &k)
    {
        std::cout << "get!\n";
        return buckets[0];
    }

    std::size_t erase(const Key &k)
    {
        std::cout << "erase!\n";
        return 0;
    }

private:
    std::size_t load_factor;
    Buckets buckets;
};

}