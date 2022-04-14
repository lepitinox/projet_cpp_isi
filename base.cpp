//
// Created by adrie on 07/04/2022.
//

#include "base.h"
#include "iostream"
#include "fstream"
#include "unordered_map"
#include "algorithm"
#include "Generic_station_parser.hpp"


base::base() = default;


void base::read_stations(const std::string &_filename) {
    std::string new_line;
    std::ifstream file(_filename);
    std::getline(file,new_line);
    int a = 0;
    while (std::getline(file,new_line)){
        int state = 0;
        std::string name,id,smolid,addr,desc;
        travel::Station tmp = travel::Station();
        for (char const&single_char: new_line){
            if (single_char==','){
                state+=1;
            }else{
                if (state == 0){
                    name+=single_char;
                }else{if (state == 1){
                        id += single_char;
                    }else{if (state == 2){
                            smolid += single_char;
                        }else{if (state == 3){
                                addr += single_char;
                            }else{if (state == 4){
                                    desc+=single_char;
                                }}}}}

            }
        }
        tmp.address = addr;
        tmp.line_id = id;
        tmp.line_name = smolid;
        tmp.name = name;
        std::cout << tmp << std::endl;
        this->stations_hashmap[a] = tmp;
        a++;
    }
    file.close();
}

void base::read_connections(const std::string &_filename) {
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

std::vector<std::pair<uint64_t, uint64_t> > base::compute_travel(uint64_t _start, uint64_t _end) {
    std::vector<uint16_t> used = std::vector<uint16_t>();
    std::vector<std::pair<uint64_t, uint64_t>> olo = std::vector<std::pair<uint64_t, uint64_t>>({});
    std::vector<std::pair<uint64_t, uint64_t>> k = base::req(_start,_end,used);
    olo.insert(olo.begin(), k.begin(),k.end());
    return olo;
}

std::vector<std::pair<uint64_t, uint64_t> > base::req(uint64_t _start, uint64_t _end, std::vector<uint16_t> _passed) {
    std::cout << "new recursion : start : " << _start << " stop : " << _end << std::endl ;
    std::vector<std::pair<uint64_t, uint64_t>> olo = std::vector<std::pair<uint64_t, uint64_t>>({});
    _passed.push_back(_start);
    for (auto const &x: connections_hashmap[_start]) {
        if (std::find(_passed.begin(), _passed.end(), x.first) != _passed.end()){

        }else{

        }
        if (x.first == _end) {
            std::pair<uint64_t, uint64_t> k = std::pair<uint64_t, uint64_t>(x.first, x.second);
            olo.insert(olo.begin(), k);
            return olo;

        } else {
            std::vector<std::pair<uint64_t, uint64_t>> res = compute_travel(x.first, _end);
            olo.insert(olo.end(), res.begin(), res.end());
        }
    }
    return olo;
}

std::vector<std::pair<uint64_t, uint64_t> > base::compute_and_display_travel(uint64_t _start, uint64_t _end) {
    std::cout << _start << _end;
    return std::vector<std::pair<uint64_t, uint64_t>>({std::pair<uint64_t, uint64_t>(1,1)});
}

