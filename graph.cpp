#include "graph.h"
#include <bits/stdc++.h>

using namespace std;
Graph::Graph(bool weighted) {
    weighted = weighted; 
    directed = false; 
}

Graph::Graph(bool weighted, bool directed){
    weighted = weighted; 
    directed = directed; 
}

vector<Vertex> Graph::getAdjacent(Vertex source) const {
    auto lookup = adjacency_list.find(source);

    if(lookup == adjacency_list.end())
        return vector<Vertex>();

    else
    {
        vector<Vertex> vertex_list;
        unordered_map <Vertex, Edge> & map = adjacency_list[source];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }
}

vector<Vertex> Graph::getVertices() const {
    vector<Vertex> ret;

    for(auto it = adjacency_list.begin(); it != adjacency_list.end(); it++)
    {
        ret.push_back(it->first);
    }

    return ret;
}

Edge Graph::getEdge(Vertex source, Vertex destination) const {
    if(assertEdgeExists(source, destination, __func__) == false)
        return Edge();
    Edge ret = adjacency_list[source][destination];
    return ret;
}

vector<Edge> Graph::getEdges() const {
    if (adjacency_list.empty())
        return vector<Edge>();

    vector<Edge> ret;
    set<pair<Vertex, Vertex>> seen;

    for (auto it = adjacency_list.begin(); it != adjacency_list.end(); it++)
    {
        Vertex source = it->first;
        for (auto its = adjacency_list[source].begin(); its != adjacency_list[source].end(); its++)
        {
            Vertex destination = its->first;
            if(seen.find(make_pair(source, destination)) == seen.end())
            {
                //this pair is never added to seen
                ret.push_back(its->second);
                seen.insert(make_pair(source,destination));
                if(!directed)
                {
                    seen.insert(make_pair(destination, source));
                }
            }
        }
    }

    return ret;
}

Edge Graph::setEdgeLabel(Vertex source, Vertex destination, string label) {
    if (assertEdgeExists(source, destination, __func__) == false)
        return InvalidEdge;
    Edge e = adjacency_list[source][destination];
    Edge new_edge(source, destination, e.getWeight(), label);
    adjacency_list[source][destination] = new_edge;

    if(!directed)
    {
        Edge new_edge_reverse(destination,source, e.getWeight(), label);
        adjacency_list[destination][source] = new_edge_reverse;
    }
    return new_edge;
}

string Graph::getEdgeLabel(Vertex source, Vertex destination) {
    if(assertEdgeExists(source, destination, __func__) == false)
        return InvalidLabel;
    return adjacency_list[source][destination].getLabel();
}

double Graph::getEdgeWeight(Vertex source, Vertex destination) const {
    if (!weighted)
        error("can't get edge weights on non-weighted graphs!");

    if(assertEdgeExists(source, destination, __func__) == false)
        return InvalidWeight;
    return adjacency_list[source][destination].getWeight();
}
void Graph::insertVertex(Vertex v) {
    removeVertex(v);
    // make it empty again
    adjacency_list[v] = unordered_map<Vertex, Edge>();
}

Vertex Graph::removeVertex(Vertex v) {
    if (adjacency_list.find(v) != adjacency_list.end())
    {
        if(!directed){
            for (auto it = adjacency_list[v].begin(); it != adjacency_list[v].end(); it++)
            {
                Vertex u = it->first;
                adjacency_list[u].erase(v); 
            }
            adjacency_list.erase(v);
            return v;
        }
        
        adjacency_list.erase(v);
        for(auto it2 = adjacency_list.begin(); it2 != adjacency_list.end(); it2++)
        {
            Vertex u = it2->first;
            if (it2->second.find(v)!=it2->second.end())
            {
                it2->second.erase(v);
            }
        }
        return v;
    }

    return InvalidVertex;
}
bool Graph::insertEdge(Vertex source, Vertex destination) {
    if(adjacency_list.find(source)!= adjacency_list.end() 
    && adjacency_list[source].find(destination)!= adjacency_list[source].end())
    {
        //edge already exit
        return false;
    }

    if(adjacency_list.find(source)==adjacency_list.end())
    {
        adjacency_list[source] = unordered_map<Vertex, Edge>();
    }
        //source vertex exists
    adjacency_list[source][destination] = Edge(source, destination);
    if(!directed)
    {
        if(adjacency_list.find(destination)== adjacency_list.end())
        {
            adjacency_list[destination] = unordered_map<Vertex, Edge>();
        }
        adjacency_list[destination][source] = Edge(source, destination);
    }
    
    return true;
}

Edge setEdgeWeight(Vertex source, Vertex destination, double weight);
bool assertEdgeExists(Vertex source, Vertex destination, string functionName) const;
void error(string message) const;

std::map<std::string, std::vector<std::string>> Graph::parse(const string& filename1) {
    std::cout<<filename1<<std::endl;
    std::vector<string> air;
    ifstream ifs(filename1);
    std::map<std::string, std::vector<std::string>> airports;
    string temp;
    string airport; 
    if(ifs.is_open()) {
     while(std::getline(ifs,airport)) {
        std::string airportID;
        vector<string> dist;
        int count = 0;
        int lat = 6; 
        int longi = 7; 
        stringstream info(airport);
        while (getline(info, temp , ',')) {
            if (count == 0) {
                airportID = temp;
                //std::cout<<"airport id: " << temp<<std::endl;
                air.push_back(temp);
            }
            if(count == 1 || count == 2) {
                if(temp[temp.length() - 1] != '\"') {
                    lat++;
                    longi++;
                }
            }
            if (count == lat || count == longi)  {
                //std::cout<<"dist: " << temp<<std::endl;
                dist.push_back(temp);
            }
            count++;
        }
        //std::cout<<dist.size()<<std::endl;
        //cout<< airportID << "," << dist[0] << "," << dist[1] << endl;
        airports.insert({airportID, dist});
     }
    }
    //std::cout<<"in the method"<<std::endl;
    //std::cout<<air.size()<<std::endl;
    return airports;
}

std::map<string, std::vector<std::pair<std::string, long double>>> Graph::routes(string filename, string filename1) {
    ifstream ifs(filename);
    string source_ID, dest_Id, temp; 
    std::map<string, std::vector<std::pair<std::string, long double>>> mappy;
    std::map<std::string, std::vector<std::string>> latlong = parse(filename1);
    // for(int i = 1; i <= 14111; i++ ){
    //     string a = to_string(i);
    //     if(latlong.count(a)) cout << a << ", " <<latlong[a][0]<< endl;
    // }
    for(string routes; std::getline(ifs,routes); routes = " ") {
        bool b = true; 
        std::vector<std::pair<std::string, long double>> related;
        int count = 0; 
        stringstream info(routes);
        while(getline(info, temp, ',')) {
            // std::cout << "reached here" << temp << std::endl;
            if(temp == "\\N") {
                  b = false; 
                    break;
                }
            if(count == 3) {
                source_ID = temp;
            }
            if(count == 5) {
                dest_Id = temp;
            }
            count++;
        }
        if(b == true) {
        unsigned int source_lat =  stoi(latlong[source_ID].at(0));
        // cout<<latlong[source_ID].at(0)<< endl;
        unsigned int source_long =  stoi(latlong[source_ID].at(1));
        // cout<<latlong[source_ID].at(1)<< endl;
        unsigned int dest_lat =  stoi(latlong[dest_Id].at(0));
        // cout<<latlong[dest_Id].at(0) << endl;
        unsigned int dest_long =  stoi(latlong[dest_Id].at(1));
        // cout<< latlong[dest_Id].at(1)<<endl;
        long double dis = distance(source_lat,source_long, dest_lat, dest_long);


        std::pair<std::string, long double> dest = make_pair(dest_Id, dis);
        
        // cout << dest.first << ", " << dest.second << endl;
            if(!mappy.count(source_ID))
            {
                related.push_back(dest);
                mappy.insert({source_ID, related});
                //cout << mappy[source_ID][0].first << endl;
            }else
            {
                mappy[source_ID].push_back(dest);
            } 
        }
    }
    // for(auto another: mappy["1"])
    // {
    //     cout << another.first << ", " << another.second<< endl;
    // }
    return mappy;
}

// int Graph::get_distance(int start_x, int start_y, int end_x, int end_y){

// }

long double Graph::toRadians(const long double ree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * ree);
}
 
long double Graph::distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
 
    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;
     
    // Calculate the result
    ans = ans * R;
 
    return ans;
}




