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

using namespace std;
// sdPair ==> string double Pair  
typedef pair<string, double> sdPair; 
class Graph {
    public: 
        Graph() = default;
        Graph(bool weighted); 
        Graph(bool weighted, bool directed);
        Graph(bool weighted, bool directed, map<string,vector<pair<string, long double>>> map);
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
        std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> getAdjList();

        void initSnapshot(string title);
        void snapshot();
        void print() const;
        bool isDirected() const;
    
        void dijkstraShortestPathh(Vertex start_airport, Vertex dest_airport);

    private: 
    
    mutable std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjacency_list;

    bool weight;
    bool direct;
    
};