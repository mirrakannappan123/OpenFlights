#include "parse.h"
#include <bits/stdc++.h>

using namespace std;
Parse::Parse() {
    graph = Graph(true, true);
}
std::map<std::string, std::vector<std::string>> Parse::parse(const string& filename1) {
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
                Vertex air_Id = temp; 
                graph.insertVertex(air_Id);
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

std::map<string, std::vector<std::pair<std::string, long double>>> Parse::routes(string filename, string filename1) {
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
        
        Vertex source = source_ID;
        Vertex d = dest_Id;
        double dist = dis; 
        graph.insertEdge(source, d);
        graph.setEdgeWeight(source, d, dist);
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

long double Parse::toRadians(const long double ree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (M_PI) / 180;
    return (one_deg * ree);
}
 
long double Parse::distance(long double lat1, long double long1,
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
Graph Parse::getGraph() {
    return graph;
}




