//
// Created by adrie on 07/04/2022.
//

#include "last.h"


std::vector<std::pair<uint64_t, uint64_t> > last::compute_travel(uint64_t _start, uint64_t _end) {
    std::vector<std::pair<uint64_t, uint64_t>> olo = std::vector<std::pair<uint64_t, uint64_t>>({});
    for (auto const &x: connections_hashmap[_start])
        if (x.first == _end) {
            std::pair<uint64_t, uint64_t> k = std::pair<uint64_t, uint64_t>(x.first, x.second);
            olo.insert(olo.begin(), k);
            return olo;

        } else {
            std::vector<std::pair<uint64_t, uint64_t>> res = compute_travel(x.first, _end);
            olo.insert(olo.end(), res.begin(), res.end());
        };
    return olo;
}
