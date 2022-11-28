#include "graph.h"
#include <bits/stdc++.h>

using namespace std;
string Graph::test(){
    return "woo";
}
std::map<std::string, std::vector<std::string>> Graph::parse(const string& filename1) {
    ifstream ifs(filename1);
    std::map<std::string, std::vector<std::string>> airports;
    string temp;
    for(string airport; std::getline(ifs,airport); airport = " ") {
        std::string airportID;
        vector<string> dist;
        int count = 0;
        stringstream info(airport);
        int lats = 6;
        int longs = 7;
        while (getline(info, temp , ',')) {
            // std::cout <<"parse " << temp <<std::endl;
            if (count == 0) {
                airportID = temp;
            }
            if (count == 1 || count == 2) {
                if (temp[temp.length() - 1] != '\"') {
                    lats++;
                    longs++;
                }
            }
            if (count == lats || count == longs)  {
                
                dist.push_back(temp);
                
                // dist.push_back(temp);
            }
            count++;
        }
        // cout<< airportID << "," << dist[0] << "," << dist[1] << endl;
        airports.insert({airportID, dist});
    }
    return airports;
}


std::map<string, std::vector<std::pair<std::string, long double>>> Graph::routes(string filename, string filename1) {
    ifstream ifs(filename);
    string source_ID, dest_Id, temp; 
    std::map<string, std::vector<std::pair<std::string, long double>>> mappy;
    std::map<std::string, std::vector<std::string>> latlong = parse(filename1);
    
    // cout << sizeof(latlong)<< endl;
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
            if (temp == "\\N") {
                b = false;
                break;
            }
            // std::cout <<"reached here" << temp <<std::endl;
            if(count == 3) {
                source_ID = temp;
            }
            if(count == 5) {
                dest_Id = temp;
            }
            count++;
        }
        if (b) {
            long double source_lat =  stoi(latlong[source_ID].at(0));
            // cout<<latlong[source_ID].at(0)<< endl;
            long double source_long =  stoi(latlong[source_ID].at(1));
            // cout<<latlong[source_ID].at(1)<< endl;
            long double dest_lat =  stoi(latlong[dest_Id].at(0));
            // cout<<latlong[dest_Id].at(0) << endl;
            long double dest_long =  stoi(latlong[dest_Id].at(1));
            // cout<< latlong[dest_Id].at(1)<<endl;
            long double dis = distance(source_lat,source_long, dest_lat, dest_long);

            std::pair<std::string, long double> dest = make_pair(dest_Id, dis);
            // cout << dest.first << ", " << dest.second << endl;
            if(!mappy.count(source_ID)) {
                related.push_back(dest);
                mappy.insert({source_ID, related});
                cout << mappy[source_ID][0].first << endl;
            }else
            {
                mappy[source_ID].push_back(dest);
            } 

        }

 
        
    }

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
