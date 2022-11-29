#pragma once 
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#include "edge.h"
using namespace std;
struct Node
{
    int val, dist;
    // Node* next;
};
 
// Data structure to store a graph edge

class Graph {
    public:
    std::map<std::string, std::vector<std::string>> parse(const string& filename);
    std::map<string, std::vector<std::pair<std::string, long double>>> routes(string filename, string filename1);
    string test();

    long double toRadians(const long double ree);
    long double distance(long double lat1, long double long1, long double lat2, long double long2);

     Graph(bool weighted); 
     Graph(bool weighted, bool directed);
     vector<Vertex> getAdjacent(Vertex source) const;
     vector<Vertex> getVertices() const;
     Edge getEdge(Vertex source, Vertex destination) const;
     vector<Edge> getEdges() const;
     Edge setEdgeLabel(Vertex source, Vertex destination, string label);
     string getEdgeLabel(Vertex source, Vertex destination);
     double getEdgeWeight(Vertex source, Vertex destination) const;
     void insertVertex(Vertex v);
     Vertex removeVertex(Vertex v);
     bool insertEdge(Vertex source, Vertex destination);
     Edge setEdgeWeight(Vertex source, Vertex destination, double weight);
    bool assertEdgeExists(Vertex source, Vertex destination, string functionName) const;
    void error(string message) const;




    private:

    std::map<std::string, std::vector<std::pair<std::string, unsigned>>> map;
    mutable std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> adjacency_list;

    bool weighted;
    bool directed;

    const static Vertex InvalidVertex;
    const static Edge InvalidEdge;
    const static int InvalidWeight;
    const static string InvalidLabel;
};


// struct Node
// {
//     int val, cost;
//     Node* next;
// };
 
// // Data structure to store a graph edge
// struct Edge {
//     int src, dest, weight;
// };
 
// class Graph
// {
//     // Function to allocate a new node for the adjacency list
//     Node* getAdjListNode(int value, int weight, Node* head);
   
 
//     int N;    // total number of nodes in the graph
 
//     public:
    
//         // An array of pointers to Node to represent the
//         // adjacency list
//         Node **head;
    
//         // Constructor
//         Graph(Edge edges[], int n, int N);
        
    
//         // Destructor
//         ~Graph();

    
// };
// void printList(Node* ptr, int i);