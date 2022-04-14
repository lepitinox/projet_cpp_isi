#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include "base.h"
#include "oklol.h"
int main() {
    base a = base();
    a.read_stations(std::string(R"(C:\Users\adrie\projet_cpp_isi\data\stations.csv)"));
    a.read_connections(R"(C:\Users\adrie\projet_cpp_isi\data\connections.csv)");
    auto vec =  a.compute_travel(9,2);
    for (auto & it : vec){
        std::cout << it.first << ": " << it.second << " :-: ";
    }


    //    mapperboi c = mapperboi();

    return 0;
}
