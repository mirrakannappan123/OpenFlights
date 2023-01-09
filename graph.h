#pragma once
#include <list>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "edge.h"
#include <unordered_map>
#include <map>
#include <set>
#include<cmath>
#include<queue>
#include<stack>
#include <bits/stdc++.h>  
using namespace std;  
#define INF double(0x3f3f3f3f) // The distance to other vertices is initialized as infinite  
using namespace std;
// diPair ==> double int Pair  
typedef pair<double, int> diPair;
struct Path
{
    vector<Vertex> path_;
    long double dist_;
};
class Graph {
    public: 
        Graph() = default;
        Graph(bool weighted); 
        Graph(bool weighted, bool directed);
        Graph(bool weighted, bool directed, map<string,vector<pair<string, long double>>> map, int total_Airlines);
        vector<Vertex> getAdjacent(Vertex source) const;
        vector<Vertex> getVertices() const;
        Edge getEdge(Vertex source, Vertex destination) const;
        vector<Edge> getEdges() const;
        //Edge setEdgeLabel(Vertex source, Vertex destination, string label);
        //string getEdgeLabel(Vertex source, Vertex destination);
        double getEdgeWeight(Vertex source, Vertex destination) const;
        void insertVertex(Vertex v);
        void insertEdge(Vertex source, Vertex destination);
        void setEdgeWeight(Vertex source, Vertex destination, double weight);
        bool assertEdgeExists(Vertex source, Vertex destination, string functionName) const;
        bool assertVertexExists(Vertex v, string functionName) const;
        void error(string message) const;


        void print() const;
        void printPath(Path input) const;
    
        std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> getAdjList();
        void addEdge(int u, int v, double w); // add edges in the graph  
    
        std::vector<Vertex> dfs();
        std::vector<Vertex> dfs(Vertex src_airport);
        void printDFS();
        // vector<Vertex> FindShortestPath(Graph& input) const;
        std::vector<Vertex> IDDFS(Vertex src, Vertex target, int max_depth);
        bool DLS(Vertex src, Vertex target, int limit);
        void printIDDFS();

        Path dijkstraShortestPath(Vertex start_airport, Vertex dest_airport);
        // void dijkstraShortestPathh(Vertex start_airport, Vertex dest_airport);
    private: 
    
        mutable std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjacency_list;

        bool weight;
        bool direct;
        list<pair<int,  double>>* adj; // the list of pair to store vertex and its weight for Dijak
        map<Vertex, int> VtIforDij; // convert string vertex of airline ID to sequential integer num
        map<int, Vertex> ItVforDij; // convert sequential integer num to vertex of airline ID
        std::vector<Vertex> path; // for dfs and IDDFS
        std::set<Vertex> visited; // for dfs and IDDFS
    
};
//
