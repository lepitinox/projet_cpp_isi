//
// Created by adrie on 31/03/2022.
//

#ifndef PROJET_CPP_ISI_OKLOL_H
#define PROJET_CPP_ISI_OKLOL_H
#include "Generic_connection_parser.hpp"

class oklol: public travel::Generic_connection_parser{
public:
    oklol();
    void read_stations(const std::string& _filename) override;
    void read_connections(const std::string& _filename) override;

};


#endif //PROJET_CPP_ISI_OKLOL_H
