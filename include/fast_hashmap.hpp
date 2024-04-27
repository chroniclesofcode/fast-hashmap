#include <cstddef>
#include <iostream>
#include <vector>
#include <optional>

namespace chronicode
{

template <typename T, typename F, typename Hash = std::hash<T>>
class fast_hashmap
{

private:
    using size_t = std::size_t;
    static constexpr size_t GSZ = 16;
    using Key = T;
    using Val = F;
    using ctrl_t = int8_t;
    using Elem = std::pair<const Key, Val>;
    using Buckets = std::vector<Elem>;
    using Controls = std::vector<ctrl_t>;

    enum Ctrl : ctrl_t
    {
        kEmpty = -128,  // 0b10000000
        kDeleted = -2,  // 0b11111110
        kSentinel = -1, // 0b11111111
        // kFull =         0b0xxxxxxx
    };

    std::size_t H1(size_t hash) { return hash >> 7; }
    ctrl_t H2(size_t hash) { return hash & 0x7F; }

    class Group
    {
    public:
        Group(size_t grp, Controls &c, Buckets &b) : curr_{grp}, ctrls_{c}, slots_{b} {}

        std::vector<size_t> match_hash(ctrl_t hash)
        {
            // When matching hash, curr_ * GSZ is the real position in array
            return {};
        }

        bool match_empty()
        {
            return true;
        }

    private:
        size_t curr_;
        Controls &ctrls_;
        Buckets &slots_;
    };

public:

    fast_hashmap(size_t sz) : load_factor_{2},
                                   num_groups_{(sz / GSZ + sz % GSZ > 0) * load_factor_},
                                   tot_elems_{num_groups_ * GSZ},
                                   ctrls_(tot_elems_),
                                   slots_(tot_elems_) {}

    fast_hashmap() : fast_hashmap(1024) {}

    class iterator
    {
    private:
        friend class fast_hashmap;
    public:
        iterator(size_t position, Controls &c, Buckets &s) : pos{position}, it_ctrl{c}, it_slots{s} {}
    private:
        size_t pos;
        Controls &it_ctrl;
        Buckets &it_slots;
    };

    inline iterator iterator_at(size_t pos)
    {
        return iterator(pos, ctrls_, slots_);
    }

    inline iterator end()
    {
        return iterator_at(tot_elems_ - 1);
    }

    // Need to distribute hash evenly between first 57 bits and last 7 bits.
    // 57 is the group location, 7 goes to the control bit.
    inline size_t calc_hash(const Key& key)
    {
        return Hash{}(key);
    }

    iterator find(const Key &key)
    {
        std::cout << "find!\n";
        size_t hash = calc_hash(key);
        size_t group = H1(hash) % num_groups_;
        while (true)
        {
            size_t pos = group * GSZ;
            Group g{pos, ctrls_, slots_};
            std::vector<size_t> found = g.match_hash(H2(hash));
            for (size_t i : found)
            {
                if (key == slots_[pos + i].first)
                    return iterator_at(pos + i);
            }
            if (g.match_empty()) return end();
            group = (group + 1) % num_groups_;
        }
    }

    bool insert(std::pair<Key, Val> elem)
    {
        std::cout << "insert!\n";
        /*
        size_t hash = calc_hash(elem.first);
        size_t pos = (H1(hash) % num_groups_) * GSZ;
        Group g{pos, ctrls_, slots_};
        */

        return true;
    }

    Val& get(const Key &key)
    {
        std::cout << "get!\n";
        return slots_[0].second;
    }

    size_t erase(const Key &key)
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