#pragma once

#include <vector>

#include "parse.h"

class Floyd {
    public: 

    Floyd(Graph& g);
    std::vector<Vertex> shortestPath(Vertex source, Vertex dest, Graph g);

    private:
    std::vector<std::vector<double>> distance; 
     std::map<Vertex, int> map;

};