#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "/workspaces/225_Final_Project/225_Final_Project/parse.h"
#include "/workspaces/225_Final_Project/225_Final_Project/floyd.h"
#include<vector>
#include<string>
#include<map>

TEST_CASE("Parse to Map Correctly", "[parse]" )
{
   Parse temp = Parse();
   string airports = "airports-extended.dat.txt";;
    string airlines = "routes.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airlines, airports);
    int number = 0;
    for(auto source: map)
    {
        for(auto dest: source.second) number++;
    }
    REQUIRE(number == temp.Valid_Airlines(airlines,airports));
}

TEST_CASE("Create a Graph Correctly", "[graph]" )
{
   Parse temp = Parse();
   string airports = "airports-extended.dat.txt";;
    string airlines = "routes.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airlines, airports);
    Graph g(true, true, map, temp.Valid_Airlines(airlines,airports));
    // bool same = true;
    for(auto src: map)
    {
        Vertex s (src.first);
        for(auto dest_map: src.second)
        {
            Vertex d(dest_map.first);
            REQUIRE(abs(g.getEdge(src.first, dest_map.first).getWeight() - dest_map.second) < 1.0 / 10000000);
        }
    }
}

TEST_CASE("Test Graph Adjacency List", "[graph]" )
{
   Parse temp = Parse();
   string airports = "airports-extended.dat.txt";;
    string airlines = "routes.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(airlines, airports);
    Graph g(true, true, map, temp.Valid_Airlines(airlines,airports));
    bool same = true;
    for(auto src: map)
    {
        vector<Vertex> adj_lists = g.getAdjacent(src.first);
        if (adj_lists.size() != src.second.size()) same = false;
        for(int i = 0; i < int(adj_lists.size()); i++)
        {
            auto res = find (adj_lists.begin(), adj_lists.end(), src.second[i].first);
//checking if the variable 'res' has index of 'last' or not
            if (res == adj_lists.end())
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


TEST_CASE("Test Small Graph constructor and Dijkstra algorithm", "[Di]" )
{
    std::map<string, std::vector<std::pair<std::string, long double>>> map 
    {
        {"airport0",{{"airport1", 10.5}, {"airport4", 100.5}, {"airport3", 30.5}}},
        {"airport1", {{"airport0", 10.5}, {"airport2", 50.5}}},
        {"airport2", {{"airport1", 50.5}, {"airport4", 10.5}, {"airport3", 20.5}}},
        {"airport3", {{"airport2", 20.5}, {"airport0", 30.5}, {"airport4", 60.5}}},
        {"airport4", {{"airport3", 60.5}, {"airport2", 10.5}, {"airport0",100.5}}}
     };

       Graph g (true, false, map,7);
       Vertex src = "airport0", dest = "airport4";
       std::vector<std::string> to_test = g.dijkstraShortestPath(src, dest).path_;
       REQUIRE(to_test.size() == 4);
       REQUIRE(to_test[0] == "airport0");
       REQUIRE(to_test[1] == "airport3");
       REQUIRE(to_test[2] == "airport2");
       REQUIRE(to_test[3] == "airport4");
       REQUIRE(g.dijkstraShortestPath(src, dest).dist_ == 61.5);
}

TEST_CASE("Finding Shortest Path for Data Graph", "[OpenFlight]" )
{
    //We thinks our algorithms work if Dijkstra and Floyd Algorithm output the same result for OpenFlight Data
    Parse temp = Parse();
    string file1 = "routes.dat.txt";
    string file2 = "airports-extended.dat.txt";
    std::map<string, std::vector<std::pair<std::string, long double>>> map = temp.routes(file1, file2);
    Graph g(true, true, map, temp.Valid_Airlines(file1,file2));
    Floyd f(g);
    Vertex src = "30", dest = "6400";

    auto vg = g.dijkstraShortestPath(src,dest).path_;
    auto vf = f.shortestPath(src,dest);

    REQUIRE(vg.size() == vf.size());
    for(int i = 0; i < int(vg.size()); i++)
    {
           REQUIRE(vg[i] == vf[i]);
    }
}

TEST_CASE("Testing DFS_path", "[DFS]") {
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
   std::vector<std::string> to_test = g.dfs();
    REQUIRE(to_test.size() == 6);
    REQUIRE(to_test[0] == "6");
    REQUIRE(to_test[1] == "3");
    REQUIRE(to_test[2] == "2");
    REQUIRE(to_test[3] == "4");
    REQUIRE(to_test[4] == "5");
    REQUIRE(to_test[5] == "1");
    
}

TEST_CASE("Testing size path", "[DFS_PATH]" )
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

   std::vector<std::string> to_test = g.dfs();
    REQUIRE(to_test.size() == 7);
    REQUIRE(to_test[0] == "7");
    REQUIRE(to_test[1] == "6");
    REQUIRE(to_test[2] == "3");
    REQUIRE(to_test[3] == "2");
    REQUIRE(to_test[4] == "4");
    REQUIRE(to_test[5] == "5");
    REQUIRE(to_test[6] == "1");
}


TEST_CASE("Testing IDDFS ", "[IDDFS]" )
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

    Vertex target = v3;
    Vertex src = v2;
    int maxDepth = 3;
    std::vector<Vertex> arr = g.IDDFS(src, target, maxDepth);
    REQUIRE(arr.size() != 0);
    REQUIRE(arr[0] == "2");
}


TEST_CASE("Testing IDDFS_2 ", "[IDDFS_2]" )
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


    Vertex target = v1;
    Vertex src = v6;
    int maxDepth = 3;
    std::vector<Vertex> arr = g.IDDFS(src, target, maxDepth);
    REQUIRE(arr.size() != 0);
    REQUIRE(arr[0] == "6");
}


