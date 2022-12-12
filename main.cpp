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
    // std::vector<Vertex> arr =    temp.getGraph().dfs();
    string airportidtwo;
    string airportidone;
    cout << "Type an airport id for the starting location: ";
    cin >> airportidone;
    cout << "Type an airport id for the destination location: ";
    cin >> airportidtwo;
    temp.getGraph().IDDFS(airportidone, airportidtwo, 3);
    // std::cout<< "arr first element" << arr[0] << std::endl;
    // std::cout<<map.size()<<std::endl;

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
    Graph g = new Graph(true, true);
    Vertex v1 = Vertex("1");
   Vertex v2 = Vertex("2");
   Vertex v3 = Vertex("3");
   Vertex v4 = Vertex("4");
   Vertex v5 = Vertex("5");
   Vertex v6 = Vertex("6");
   Vertex v7 = Vertex("7");

   g.insertVertex(v1);
   g.insertVertex(v2);
   g.insertVertex(v3);
   g.insertVertex(v4);
   g.insertVertex(v5);
   g.insertVertex(v6);
   g.insertVertex(v7);

   g.insertEdge(v1, v3);
   g.setEdgeWeight(v1,v3, 9);
   g.insertEdge(v1, v2);
   g.setEdgeWeight(v1, v2, 7);
   g.insertEdge(v2, v4);
   g.setEdgeWeight(v2, v4, 15);
   g.insertEdge(v3, v4);
   g.setEdgeWeight(v3, v4, 11);
   g.insertEdge(v4, v5);
   g.setEdgeWeight(v4, v5, 6);
   g.insertEdge(v5, v6);
   g.setEdgeWeight(v5, v6, 9);
   g.insertEdge(v6, v1);
   g.setEdgeWeight(v6, v1, 14);
   g.insertEdge(v6, v3);
   g.setEdgeWeight(v6, v3, 2);
   g.insertEdge(v2, v3);
   g.setEdgeWeight(v2, v3, 10);

 

    //  Vertex target = v5;
    //  Vertex src = v2;
    //  int maxDepth = 3;
    //  std::vector<Vertex> arrr = g.IDDFS(src, target, maxDepth);
    //  for(size_t i = 0; i < arrr.size(); i++) {
    //         std::cout << "iids ouput" <<arrr[i]  << std::endl; 
    // }
     
    //  if (g.IDDFS(src, target, maxDepth).size() != 0)
    //     cout << "Target is reachable from source "
    //             "within max depth";
    // else
    //     cout << "Target is NOT reachable from source "
    //             "within max depth";



}


 
