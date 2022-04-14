//
// Created by adrie on 31/03/2022.
//

#ifndef PROJET_CPP_ISI_TEST_H
#define PROJET_CPP_ISI_TEST_H
#include "Generic_station_parser.hpp"

class test: public travel::Generic_station_parser {
public:
    test();
    void read_stations(const std::string& _filename) override;
};


#endif //PROJET_CPP_ISI_TEST_H
