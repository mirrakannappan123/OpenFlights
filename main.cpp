#include <iostream>
#include <sstream>
#include <string>
#include "parse.h"
#include "floyd.h"

using namespace std;


// Graph implementation in C++ without using STL
int main()
{   
   // graph edges array.
    Parse temp = Parse();
    
   std::cout << "This is us parsing through the airport and route files and putting it in a map" <<std::endl;
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    // DFS traversal
    std::vector<Vertex> arr =    temp.getGraph().dfs();
    string airportidtwo;
    string airportidone;
    cout << "Type an airport id for the starting location: ";
    cin >> airportidone;
    cout << "Type an airport id for the destination location: ";
    cin >> airportidtwo;

    // IDDFS traversal 
    temp.getGraph().IDDFS(airportidone, airportidtwo, 3);

    //Iterating through the adjacency list 
    for(auto route: map){
        //std::cout<<"in the loop"<<std::endl;
        for(auto adj: route.second){
            std::cout<<route.first<<std::endl;
            std::vector<Vertex> test = temp.getGraph().getAdjacent(route.first); 
            //std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
            for(size_t i = 0; i < test.size(); i++) {
                std::cout << test[i] <<std::endl;
            }
            break;
        }
        break;
    }
    cout << "cout" << endl;



    // string airportidtwo;
    // string airportidone;
    // cout << "Type an airport id for the starting location: ";
    // cin >> airportidone;
    // cout << "Type an airport id for the destination location: ";
    // cin >> airportidtwo;

    // Floyd f(g);
    // std::vector<string> vec = f.shortestPath(airportidone, airportidtwo);
    // for (string s : vec)
    // {
    //     std::cout << s << ", " << std::endl;
    // }


 

  



}


 
