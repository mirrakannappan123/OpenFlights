#include "floyd.h"
#include<iostream>

Floyd::Floyd(Graph g) {
    double inf = 1e9;
    std::vector<Vertex> ver = g.getVertices();
    std::cout<<ver.size()<<std::endl;

    distance = vector<vector<double>>(ver.size(), vector<double>(ver.size(), inf));
    path = vector<vector<std::string>>(ver.size(), vector<std::string>(ver.size(), "-1"));

    for(size_t i = 0; i < ver.size(); i++) {
         map[ver[i]] = i;
         for(size_t j = 0; j < ver.size(); j++) {
             if(i == j) {
                 distance[i][j] = 0; 
                 path[i][j] = ver[i];
             }
         }
        for(size_t k = 0; k < ver.size(); k++) {
            std::cout<<ver[i] << " " << ver[k]<<std::endl;
            if (g.assertEdgeExists(ver[i], ver[k], " ")) {
                distance[i][k] = g.getEdgeWeight(ver[i], ver[k]);
                path[i][k] = ver[k];
            } 
        }
    } 
    for (size_t k = 0; k < ver.size(); k++) {
        for (size_t i = 0; i < ver.size(); i++) {
            for (size_t j = 0; j < ver.size(); j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

std::vector<string> Floyd::shortestPath(Vertex source, Vertex dest) {
    std::vector<string> to_return;
    Vertex curr = source; 
    if (path[map[curr]][map[dest]] == "-1") {
        to_return.push_back("no path");
        return to_return;
    }

    while (curr != dest) {
        to_return.push_back(curr);
        curr = path[map[curr]][map[dest]];
    }
    to_return.push_back(dest);
    return to_return;

}