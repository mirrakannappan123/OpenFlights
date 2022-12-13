#pragma once 
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

#include "graph.h"
using namespace std;
struct Node
{
    int val, dist;
    // Node* next;
};
 
// Data structure to store a graph edge

class Parse {
    public:
    // std::map<std::string, std::vector<std::string>> parse(const string& filename);
    // std::map<string, std::vector<std::pair<std::string, long double>>> routes(string filename, string filename1);
    std::map<std::string, std::vector<long double>> parse(const string& filename);
    std::map<string, std::vector<std::pair<std::string, long double>>> routes(string filename, string filename1);
    int Valid_Airlines(string filename, string filename1);
    // int Valid_Airlines(string filename);
    string test();
    Parse();
    Graph getGraph();

    long double toRadians(const long double ree);
    long double distance(long double lat1, long double long1, long double lat2, long double long2);



    private:

    std::map<std::string, std::vector<std::pair<std::string, unsigned>>> map;
    Graph graph; 
    
};
 //std::map<std::string, std::vector<std::pair<std::string, unsigned>>> map;

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