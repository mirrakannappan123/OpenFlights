#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "parse.h"
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