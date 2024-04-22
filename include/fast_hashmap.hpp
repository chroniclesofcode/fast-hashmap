#include <cstddef>
#include <iostream>
#include <vector>

namespace chronicode
{

template <typename T, typename F, typename Hash = std::hash<T>>
class fast_hashmap
{

private:

    static constexpr std::size_t GSZ = 16;
    using Key = T;
    using Val = F;
    using ctrl_t = int8_t;
    using Elem = std::pair<Key, Val>;
    using Buckets = std::vector<Elem>;
    using Controls = std::vector<ctrl_t>;

    enum Ctrl : ctrl_t
    {
        kEmpty = -128,  // 0b10000000
        kDeleted = -2,  // 0b11111110
        kSentinel = -1, // 0b11111111
        // kFull =         0b0xxxxxxx
    };

    std::size_t H1(std::size_t hash) { return hash >> 7; }
    ctrl_t H2(std::size_t hash) { return hash & 0x7F; }

public:

    fast_hashmap(std::size_t sz) : load_factor_{2},
                                   num_groups_{(sz / GSZ + sz % GSZ > 0) * load_factor_},
                                   tot_elems_{num_groups_ * GSZ},
                                   ctrls_(tot_elems_),
                                   slots_(tot_elems_) {}

    fast_hashmap() : fast_hashmap(1024) {}

    bool insert(const Key &k, Val v)
    {
        std::cout << "insert!\n";
        return true;
    }

    Val& get(const Key &k)
    {
        std::cout << "get!\n";
        return slots_[0].second;
    }

    std::size_t erase(const Key &k)
    {
        std::cout << "erase!\n";
        return 0;
    }

private:

private:
    std::size_t load_factor_;
    std::size_t num_groups_;
    std::size_t tot_elems_;
    Controls ctrls_;
    Buckets slots_;
};

}