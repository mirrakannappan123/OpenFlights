#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "edge.h"
#include <unordered_map>
#include <set>

using namespace std;
class Graph {
    public: 

    Graph(bool weighted); 
     Graph(bool weighted, bool directed);
     vector<Vertex> getAdjacent(Vertex source) const;
     vector<Vertex> getVertices() const;
     Edge getEdge(Vertex source, Vertex destination) const;
     vector<Edge> getEdges() const;
     //Edge setEdgeLabel(Vertex source, Vertex destination, string label);
     //string getEdgeLabel(Vertex source, Vertex destination);
     double getEdgeWeight(Vertex source, Vertex destination) const;
     void insertVertex(Vertex v);
     Vertex removeVertex(Vertex v);
     void insertEdge(Vertex source, Vertex destination);
     void setEdgeWeight(Vertex source, Vertex destination, double weight);
    bool assertEdgeExists(Vertex source, Vertex destination, string functionName) const;
    bool assertVertexExists(Vertex v, string functionName) const;
    void error(string message) const;

    private: 
    mutable std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjacency_list;

    bool weight;
    bool direct;

    const static Vertex InvalidVertex;
    const static Edge InvalidEdge;
    const static int InvalidWeight;
    const static string InvalidLabel;
};