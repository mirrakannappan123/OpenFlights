#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "/workspaces/Final Project - Mirra/225_Final_Project/parse.h"
#include "/workspaces/Final Project - Mirra/225_Final_Project/floyd.h"
#include<vector>
#include<string>
#include<map>

TEST_CASE("Parse to Map Correctly", "[parse]" )
{
   Parse temp = Parse();
   string airports = "225_Final_Project/airports-extended.dat.txt";
    string airlines = "225_Final_Project/airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airports, airlines);
    int number = 0;
    for(auto source: map)
    {
        for(auto dest: source.second) number++;
    }
    REQUIRE(number == temp.Valid_Airlines(airports));
}

TEST_CASE("Create a Graph Correctly", "[graph]" )
{
   Parse temp = Parse();
   string airports = "225_Final_Project/airports-extended.dat.txt";
    string airlines = "225_Final_Project/airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airports, airlines);
    Graph g(true, true, map);
    bool same = true;
    for(auto src: map)
    {
        for(auto dest_map: src.second)
        {
            if(g.getEdge(src.first, dest_map.first).getWeight() != dest_map.second) same = false;
        }
    }
    REQUIRE(same == true);
}

TEST_CASE("Test Graph Adjacency List", "[graph]" )
{
   Parse temp = Parse();
   string airports = "225_Final_Project/airports-extended.dat.txt";
    string airlines = "225_Final_Project/airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airports, airlines);
    Graph g(true, true, map);
    bool same = true;
    for(auto src: map)
    {
        vector<Vertex> adj_lists = g.getAdjacent(src.first);
        if (adj_lists.size() != src.second.size()) same = false;
        for(unsigned i = 0; i < adj_lists.size(); i++)
        {
            if(adj_lists[i] != src.second[i].first)
            {
                same = false;
            }

        }
    }
    REQUIRE(same == true);
}

TEST_CASE("Finds Shortest Path Using Floyd Algorithm", "[Floyd]" )
{
   Graph g = new Graph(true, true); 

   Vertex v1 = Vertex("1");
   Vertex v2 = Vertex("2");
   Vertex v3 = Vertex("3");
   Vertex v4 = Vertex("4");
   Vertex v5 = Vertex("5");
   Vertex v6 = Vertex("6");

   g.insertVertex(v1);
   g.insertVertex(v2);
   g.insertVertex(v3);
   g.insertVertex(v4);
   g.insertVertex(v5);
   g.insertVertex(v6);

   g.insertEdge(v1, v3);
   g.setEdgeWeight(v1,v3, 9);
   g.insertEdge(v1, v2);
   g.setEdgeWeight(v1, v2, 7);
   g.insertEdge(v2, v4);
   g.setEdgeWeight(v2, v4, 15);
   g.insertEdge(v3, v4);
   g.setEdgeWeight(v3, v4, 11);
   g.insertEdge(v4, v5);
   g.setEdgeWeight(v4, v5, 6);
   g.insertEdge(v5, v6);
   g.setEdgeWeight(v5, v6, 9);
   g.insertEdge(v6, v1);
   g.setEdgeWeight(v6, v1, 14);
   g.insertEdge(v6, v3);
   g.setEdgeWeight(v6, v3, 2);
   g.insertEdge(v2, v3);
   g.setEdgeWeight(v2, v3, 10);

   Floyd f(g);
   std::vector<std::string> to_test = f.shortestPath(v1, v5);
    REQUIRE(to_test.size() == 4);
    REQUIRE(to_test[0] == "1");
    REQUIRE(to_test[1] == "3");
    REQUIRE(to_test[2] == "6");
    REQUIRE(to_test[3] == "5");
}

TEST_CASE("Finds Shortest Path Using Floyd Algorithm: No Path", "[Floyd]" )
{
   Graph g = new Graph(true, true); 

   Vertex v1 = Vertex("1");
   Vertex v2 = Vertex("2");
   Vertex v3 = Vertex("3");
   Vertex v4 = Vertex("4");
   Vertex v5 = Vertex("5");
   Vertex v6 = Vertex("6");
   Vertex v7 = Vertex("7");

   g.insertVertex(v1);
   g.insertVertex(v2);
   g.insertVertex(v3);
   g.insertVertex(v4);
   g.insertVertex(v5);
   g.insertVertex(v6);
   g.insertVertex(v7);

   g.insertEdge(v1, v3);
   g.setEdgeWeight(v1,v3, 9);
   g.insertEdge(v1, v2);
   g.setEdgeWeight(v1, v2, 7);
   g.insertEdge(v2, v4);
   g.setEdgeWeight(v2, v4, 15);
   g.insertEdge(v3, v4);
   g.setEdgeWeight(v3, v4, 11);
   g.insertEdge(v4, v5);
   g.setEdgeWeight(v4, v5, 6);
   g.insertEdge(v5, v6);
   g.setEdgeWeight(v5, v6, 9);
   g.insertEdge(v6, v1);
   g.setEdgeWeight(v6, v1, 14);
   g.insertEdge(v6, v3);
   g.setEdgeWeight(v6, v3, 2);
   g.insertEdge(v2, v3);
   g.setEdgeWeight(v2, v3, 10);

   Floyd f(g);
   std::vector<std::string> to_test = f.shortestPath(v1, v7);
    REQUIRE(to_test.size() == 1);
    REQUIRE(to_test[0] == "no path");
}