#include <iostream>
#include <sstream>
#include <string>
#include "parse.h"
#include "floyd.h"

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
    std::vector<Vertex> arr =    temp.getGraph().dfs();
    std::cout<< "arr first element" << arr[0] << std::endl;
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

    std::map<string, std::vector<std::pair<std::string, long double>>> mappy {
        {"airport0",{{"airport1", 10.5}, {"airport4", 100.5}, {"airport3", 30.5}}},
        {"airport1", {{"airport0", 10.5}, {"airport2", 50.5}}},
        {"airport2", {{"airport1", 50.5}, {"airport4", 10.5}, {"airport3", 20.5}}},
        {"airport3", {{"airport2", 20.5}, {"airport0", 30.5}, {"airport4", 60.5}}},
        {"airport4", {{"airport3", 60.5}, {"airport2", 10.5}, {"airport0",100.5}}}
     };
     Graph g = temp.getGraph();

    string airportidtwo;
    string airportidone;
    cout << "Type an airport id for the starting location: ";
    cin >> airportidone;
    cout << "Type an airport id for the destination location: ";
    cin >> airportidtwo;

    Floyd f(g);
    std::vector<string> vec = f.shortestPath(airportidone, airportidtwo);
    for (string s : vec)
    {
        std::cout << s << ", " << std::endl;
    }

    //  Graph g = new Graph(true, true);

    //  g.insertVertex("airport0");
    //  g.insertVertex("airport1");
    //  g.insertVertex("airport2");
    //  g.insertVertex("airport3");
    //  g.insertVertex("airport4");

    //  g.insertEdge("airport0","airport1");
    //  g.setEdgeWeight("airport0","airport1", 10.5);
    //  g.insertEdge("airport0","airport4");
    //  g.setEdgeWeight("airport0","airport4", 100.5);
    //  g.insertEdge("airport0","airport3");
    //  g.setEdgeWeight("airport0","airport3", 30.5);
    //  g.insertEdge("airport1","airport2");
    //  g.setEdgeWeight("airport1","airport2", 50.5);
    //  g.insertEdge("airport2","airport3");
    //  g.setEdgeWeight("airport2","airport3", 20.5);
    //  g.insertEdge("airport3","airport4");
    //  g.setEdgeWeight("airport3","airport4", 60.5);
    //  g.insertEdge("airport2","airport4");
    //  g.setEdgeWeight("airport2","airport4", 10.5);


    //  g.dijkstraShortestPathh("airport0", "airport4");
}
// #include <iostream>
// #include <sstream>
// #include <string>
// #include "graph.h"
// #include <regex>
// #include <iterator>



// using namespace std;

 
// // Graph implementation in C++ without using STL
// int main()
// {   
//     Graph temp = Graph();
//     string file1 = "routes.dat.txt";
//     string file2 = "airports-extended.dat.txt";
//     // std::map<std::string, std::vector<std::string>> mappy = temp.parse(file2);
//     std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
//     int count = 0;
                
//     // for(auto route: map){
//     //     for(auto adj: route.second){

             
//     //         std::cout << "(" << route.first << ", " << adj.first  << " )" << std::endl;
//     //     }
//     // }

    
//     cout << "cout" << count << endl;
// }
