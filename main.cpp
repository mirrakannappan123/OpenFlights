#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"


using namespace std;

 
// Graph implementation in C++ without using STL
int main()
{   
    Graph temp = Graph();
    // string file1 = "/workspaces/225_Final_Project/225_Final_Project/routes.dat.txt";
    // string file2 = "/workspaces/225_Final_Project/225_Final_Project/airports-extended.dat.txt";
    // std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    // for(auto route: map){
    //     for(auto adj: route.second){
    //         std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
    //     }
    // }
    cout<< temp.test();
}