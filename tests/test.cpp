#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "/workspaces/225_Final_Project/225_Final_Project/parse.h"
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

TEST_CASE("Create a Graph Correctly", "[parse]" )
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