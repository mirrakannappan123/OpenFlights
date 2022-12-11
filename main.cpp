#include <iostream>
#include <sstream>
#include <string>
#include "parse.h"
#include "floyd.h"


using namespace std;


int main()
{   
   // graph edges array.
    Parse temp = Parse();
    std::cout << "This is us parsing through the airport and route files and putting it in a map" <<std::endl;
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    Graph g(true, true, map);
    Floyd f(g);

    //int total = 0; //total number of airlines
    for(auto route: map){
        for(auto adj: route.second){
            std::cout << "( Source ID: " << route.first << ",  Destination ID: " << adj.first << ",  How far: " << adj.second << " )" << std::endl;
            std::vector<std::string> to_return = f.shortestPath(route.first, adj.first);
            for(size_t i = 0; i < to_return.size(); i++) {
                std::cout<<to_return[i]<< " ";
        }
    }
    }

 
    // cout<<"The total number of airlines are:" << temp.Valid_Airlines(file1)<<endl;
    // cout<<"The total number of airlines that are traversed through map created by parse function are : " << temp.Valid_Airlines(file1)<<endl;

    // cout << "-------------------------------------------------------------------------"<< endl;
    // cout << "Graph Representation:"<< endl;
    // Graph g(true, true, map);
    // //vector<Vertex> vertices = g.getVertices();
    // // for(auto src: vertices)
    // // {
    // //     vector<Vertex> adj_lists = g.getAdjacent(src);
    // //     cout<< "( Source Vertex: " <<  src << ", Adj_Lists:{";
    // //     for(auto adj: adj_lists) cout << adj << ", ";
    // //     cout << "})" << endl;
    // // }
    // //std::cout<<vertices[3]<<" " <<vertices[15]<<std::endl;
    // Floyd f = Floyd(g);
    // std::vector<std::string> to_return = f.shortestPath(vertices[3], vertices[1]);
    // //std::cout<<vertices[3]<<" " <<vertices[15]<<std::endl;
    // for(size_t i = 0; i < to_return.size(); i++) {
    //     std::cout<<to_return[i]<< " ";
    // }
// void display_AdjList(adjNode* ptr, int i)
// {
//     while (ptr != nullptr) {
//         cout << "(" << i << ", " << ptr->val
//             << ", " << ptr->cost << ") ";
//         ptr = ptr->next;
//     }
//     cout <<endl;
    // cout << "cout" << endl;
    // std::vector<Vertex> test = temp.getGraph().getAdjacent(); 

    
    //std::cout<<temp.getGraph().getAdjacent(664)<<std::endl;
    // for(auto route: map){
    //     //std::cout<<"in the loop"<<std::endl;
    //     for(auto adj: route.second){
    //         std::cout<<route.first<<std::endl;
    //         std::vector<Vertex> test = temp.getGraph().getAdjacent(route.first); 
    //         //std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
    //         for(size_t i = 0; i < test.size(); i++) {
    //             std::cout << test[i] <<std::endl;
    //         }
    //         break;
    //     }
    //     break;
    // }
    // cout << "cout" << endl;
}