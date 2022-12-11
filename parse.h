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
    std::map<std::string, std::vector<std::string>> parse(const string& filename);
    std::map<string, std::vector<std::pair<std::string, long double>>> routes(string filename, string filename1);
    string test();
    Parse();
    Graph getGraph();

    long double toRadians(const long double ree);
    long double distance(long double lat1, long double long1, long double lat2, long double long2);



    private:

    std::map<std::string, std::vector<std::pair<std::string, unsigned>>> map;
    Graph graph; 
    
};
