//
// Created by adrie on 07/04/2022.
//

#ifndef PROJET_CPP_ISI_LAST_H
#define PROJET_CPP_ISI_LAST_H
#include "Generic_mapper.hpp"

class last: travel::Generic_mapper {
    void read_stations(const std::string& _filename) override;
    void read_connections(const std::string& _filename) override;
    std::vector<std::pair<uint64_t,uint64_t> > compute_travel(uint64_t _start, uint64_t _end) override;
    std::vector<std::pair<uint64_t,uint64_t> > compute_and_display_travel(uint64_t _start, uint64_t _end) override = 0;

    std::vector<std::pair<uint64_t,uint64_t> > compute_travel(const std::string&, const std::string&) override{
        throw("Nothing here");
    }
    std::vector<std::pair<uint64_t,uint64_t> > compute_and_display_travel(const std::string&, const std::string&) override{
        throw("Nothing here");}
};


#endif //PROJET_CPP_ISI_LAST_H
