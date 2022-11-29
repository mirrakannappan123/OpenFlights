#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"


using namespace std;

 
// Graph implementation in C++ without using STL
int main()
{   
    Graph temp = Graph(45);
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    std::cout<<map.size()<<std::endl;

    for(auto route: map){
        std::cout<<"in the loop"<<std::endl;
        for(auto adj: route.second){
            std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
        }
    }
    cout << "cout" << endl;
}