#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"
#include <regex>
#include <iterator>



using namespace std;

 
// Graph implementation in C++ without using STL
int main()
{   
    Graph temp = Graph();
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    // std::map<std::string, std::vector<std::string>> mappy = temp.parse(file2);
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    int count = 0;
                
    // for(auto route: map){
    //     for(auto adj: route.second){

             
    //         std::cout << "(" << route.first << ", " << adj.first  << " )" << std::endl;
    //     }
    // }

    
    cout << "cout" << count << endl;
}
