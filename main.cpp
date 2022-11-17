#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"


using namespace std;

 
// Graph implementation in C++ without using STL
int main()
{   
    Graph temp = Graph();

    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes("/workspaces/inc-chipmunk/routes.dat.txt", "/workspaces/inc-chipmunk/airports-extended.dat.txt");
    for(auto route: map){
        for(auto adj: route.second){
            std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
        }
    }
}