//
// Created by adrie on 31/03/2022.
//

#include "oklol.h"
#include "iostream"
#include "fstream"

oklol::oklol() {

}

void oklol::read_stations(const std::string &_filename) {
    std::cout<<_filename;
}

void oklol::read_connections(const std::string &_filename) {
    std::string new_line;
    std::ifstream file(_filename);
    std::getline(file,new_line);
    int a = 0;
    while (std::getline(file,new_line)){
        int state = 0;
        std::string from,to,min;
        for (char const&single_char: new_line) {
            if (single_char == ',') {
                state += 1;
            } else {
                if (state == 0) {
                    from += single_char;
                } else {
                    if (state == 1) {
                        to += single_char;
                    } else {
                        if (state == 2) {
                            min += single_char;
                        }
                    }
                }

            }
        }
        if (connections_hashmap.find(std::stoi(from)) == connections_hashmap.end()){
            std::unordered_map<uint64_t,uint64_t> tmp;
            tmp[std::stoi(to)]=std::stoi(min);
            this->connections_hashmap[std::stoi(from)]=tmp;
        }else{
            std::unordered_map<uint64_t,uint64_t> tmp = connections_hashmap[std::stoi(from)];
            tmp[std::stoi(to)]=std::stoi(min);
            this->connections_hashmap[std::stoi(from)]=tmp;
        }

        a++;
    }
    file.close();

    for (auto const& x: this->connections_hashmap){
        std::cout << x.first  // string (key)
                  << std::endl;
        for (auto const& aa : x.second){
            std::cout << aa.first  // string (key)
                      << ':'
                      << aa.second // string's value
                      << std::endl;

        }
        std::cout << std::endl;
    }
}

