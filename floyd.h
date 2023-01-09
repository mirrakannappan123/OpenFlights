#pragma once

#include <vector>

#include "parse.h"

class Floyd {
    public: 

    Floyd(Graph g);
    std::vector<string> shortestPath(Vertex source, Vertex dest);

    private:
    std::vector<std::vector<double>> distance; 
    std::vector<std::vector<std::string>> path; 
     std::map<Vertex, int> map;

};