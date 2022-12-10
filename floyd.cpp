#include "floyd.h"

Floyd::Floyd(Graph& g) {
    double inf = 1e9;
    std::vector<Vertex> ver = g.getVertices();

    distance = vector<vector<double>>(ver.size(), vector<double>(ver.size(), inf));

    for(size_t i = 0; i < ver.size(); i++) {
        map[ver[i]] = i; 
        for(size_t j = 0; j < ver.size(); j++) {
            if(i == j) {
                distance[i][j] = 0;
            } else {
                distance[i][j] = inf;
            }
        }
        for(size_t k = 0; k < ver.size(); k++) {
            if (g.assertEdgeExists(ver[i], ver[k], "")) {
                distance[i][k] = g.getEdgeWeight(ver[i], ver[k]);
            }
        }
    } 
    for (size_t k = 0; k < ver.size(); k++) {
        for (size_t i = 0; i < ver.size(); i++) {
            for (size_t j = 0; j < ver.size(); j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}