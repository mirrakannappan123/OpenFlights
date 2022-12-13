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
    int total = 0; //total number of airlines
    for(auto route: map){
        for(auto adj: route.second){
            // std::cout << "( Source ID: " << route.first << ",  Destination ID: " << adj.first << ",  How far: " << adj.second << " )" << std::endl;
            total++;
        }
    }
 
    cout<<"The total number of airlines are:" << temp.Valid_Airlines(file1,file2)<<endl;
    cout<<"The total number of airlines that are traversed through map created by parse function are : " << temp.Valid_Airlines(file1,file2)<<endl;

    cout << "-------------------------------------------------------------------------"<< endl;
    cout << "Graph Representation:"<< endl;
    Graph g(true, true, map, temp.Valid_Airlines(file1,file2));
    vector<Vertex> vertices = g.getVertices();
    for(auto src: vertices)
    {
        vector<Vertex> adj_lists = g.getAdjacent(src);
        cout<< "( Source Vertex: " <<  src << ", Adj_Lists:{";
        for(auto adj: adj_lists) cout << adj << ", ";
        cout << "})" << endl;
    }
    cout << "-------------------------------------------------------------------------"<< endl;
    cout << "Find Shortest Path"<< endl;
  
    Vertex src = "", dest = "";
    cout << "Enter your source airport ID below:" << endl << "> ";
    cin >> src;
    cout << "Enter your dest airport ID below:" << endl << "> ";
    cin>>dest;
    g.printPath(g.dijkstraShortestPath(src, dest));
    Floyd f(g);
    g.printPath({f.shortestPath(src, dest),0});
 
}

// 
