#include <iostream>
#include <sstream>
#include <string>
#include "parse.h"


using namespace std;

// void display_AdjList(adjNode* ptr, int i)
// {
//     while (ptr != nullptr) {
//         cout << "(" << i << ", " << ptr->val
//             << ", " << ptr->cost << ") ";
//         ptr = ptr->next;
//     }
//     cout <<endl;

// Graph implementation in C++ without using STL
int main()
{   
   // graph edges array.
    Parse temp = Parse();


   std::cout << "This is us parsing through the airport and route files and putting it in a map" <<std::endl;
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);


    //std::vector<Vertex> test = temp.getGraph().getAdjacent(); 

    
    //std::cout<<temp.getGraph().getAdjacent(664)<<std::endl;
    std::cout<<map.size()<<std::endl;

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
}