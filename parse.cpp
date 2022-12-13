#include "parse.h"
#include <bits/stdc++.h>

using namespace std;
Parse::Parse() {
    graph = Graph(true, true);
}

std::map<std::string, std::vector<long double>> Parse::parse(const string& filename1) {
    ifstream ifs(filename1);
    std::map<std::string, std::vector<long double>> airports;
    string temp;
    for(string airport; std::getline(ifs,airport); airport = " ") 
    {
        std::string airportID;
        vector<long double> dist;
        int count = 0, lat_access = 6, long_access = 7;
        stringstream info(airport);
        while (getline(info, temp , ',')) {
            if (count == 0) 
            {
                airportID = temp;
            }
            if (count == lat_access || count == long_access)  
            {
                try
                {
                long double latlong = stod(temp);
                    // cout << latlong << endl;
                    dist.push_back(latlong);
                }catch(std::invalid_argument& error)
                {
                    lat_access ++;
                    long_access ++;
                }
            }
            count++;
        }
        airports.insert({airportID, dist});
    }
    return airports;
}

std::map<string, std::vector<std::pair<std::string, long double>>> Parse::routes(string filename, string filename1) {
    ifstream ifs(filename);
    string source_ID, dest_Id, temp; 
    std::map<string, std::vector<std::pair<std::string, long double>>> mappy;
    std::map<std::string, std::vector<long double>> latlong = parse(filename1);
    // cout << sizeof(latlong)<< endl;
    // for(int i = 1; i <= 14111; i++ ){
    //     string a = to_string(i);
    //     if(latlong.count(a)) cout << a << ", " <<latlong[a][0]<< endl;
    // }
    for(string routes; std::getline(ifs,routes); routes = " ") {
        std::vector<std::pair<std::string, long double>> related;
        int count = 0; 
        stringstream info(routes);
        while(getline(info, temp, ',')) {
    
            if(count == 3 ) {
                source_ID = temp;
            }
            if(count == 5) {
                dest_Id = temp;
            }
            count++;
        }
        if(dest_Id == "\\N" || source_ID == "\\N") continue;
        // unsigned int source_lat =  stoi("1");
        // unsigned int source_long =  stoi("2");
        // unsigned int dest_lat =  stoi("3");
        // unsigned int dest_long =  stoi("4");
        // cout << source_ID << endl;
        // cout<<latlong[source_ID].at(0)<< endl;
        // cout<<latlong[source_ID].at(1)<< endl;
        // cout<<latlong[dest_Id].at(0) << endl;
        // cout<< latlong[dest_Id].at(1)<<endl;
        long double source_lat = latlong[source_ID].at(0);
        long double source_long = latlong[source_ID].at(1);
        long double dest_lat = latlong[dest_Id].at(0);
        long double dest_long = latlong[dest_Id].at(1);

        long double dis = distance(source_lat,source_long, dest_lat, dest_long);

        std::pair<std::string, long double> dest = make_pair(dest_Id, dis);
        // cout << dest.first << ", " << dest.second << endl;
        if(!mappy.count(source_ID))
        {
            related.push_back(dest);
            mappy.insert({source_ID, related});
            // cout << mappy[source_ID][0].first << endl;
        }else
        {
            //make sure that there is no two same destination airport
            bool existed = false;
            for(auto ele: mappy[source_ID])
            {
                if(ele.first == dest.first)
                {
                   existed = true;
                   break;
                }
            }
            if(!existed) mappy[source_ID].push_back(dest);
        } 
    }
    return mappy;
}
int Parse::Valid_Airlines(string filename, string filename1) {
    ifstream ifs(filename);
    string source_ID, dest_Id, temp; 
    std::map<string, std::vector<std::pair<std::string, long double>>> mappy;
    std::map<std::string, std::vector<long double>> latlong = parse(filename1);
    int total = 0;
    // cout << sizeof(latlong)<< endl;
    // for(int i = 1; i <= 14111; i++ ){
    //     string a = to_string(i);
    //     if(latlong.count(a)) cout << a << ", " <<latlong[a][0]<< endl;
    // }
    for(string routes; std::getline(ifs,routes); routes = " ") {
        std::vector<std::pair<std::string, long double>> related;
        int count = 0; 
        stringstream info(routes);
        while(getline(info, temp, ',')) {
    
            if(count == 3 ) {
                source_ID = temp;
            }
            if(count == 5) {
                dest_Id = temp;
            }
            count++;
        }
        if(dest_Id == "\\N" || source_ID == "\\N") continue;
     

        long double dis = 0.0;

        std::pair<std::string, long double> dest = make_pair(dest_Id, dis);
        // cout << dest.first << ", " << dest.second << endl;
        if(!mappy.count(source_ID))
        {
            related.push_back(dest);
            mappy.insert({source_ID, related});
            // cout << mappy[source_ID][0].first << endl;
            total++;
        }else
        {
            //make sure that there is no two same destination airport
            bool existed = false;
            for(auto ele: mappy[source_ID])
            {
                if(ele.first == dest.first)
                {
                   existed = true;
                   break;
                }
            }
            if(!existed)
            {
                mappy[source_ID].push_back(dest);
                total++;
            }
        } 
    }
    return total;
}
// int Parse::Valid_Airlines(string filename)
// {
//     int total = 0;
//     ifstream ifs(filename);
//     for(string routes; std::getline(ifs,routes); routes = " ")
//     {
//         int count = 0; 
//         stringstream info(routes);
//         string temp, source_ID, dest_ID;
//         while(getline(info, temp, ',')) {
            
//             if(count == 3 ) {
//                 source_ID = temp;
//             }
//             if(count == 5) {
//                 dest_ID = temp;
//             }
//             count++;
//         }
//         if(dest_ID == "\\N" || source_ID == "\\N") continue;
        
//         total++;
//     }
//     return total;
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
//




