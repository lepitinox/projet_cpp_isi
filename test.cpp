//
// Created by adrie on 31/03/2022.
//

#include "test.h"
#include "iostream"
#include "fstream"
#include "unordered_map"
#include <codecvt>
#include "Generic_station_parser.hpp"


void test::read_stations(const std::string &_filename) {
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

test::test() {}
