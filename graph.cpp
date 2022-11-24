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
        while (getline(info, temp , ',')) {
            if (count == 0) {
                airportID = temp;
            }
            if (count == 6 || count == 7)  {
                dist.push_back(temp);
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
        std::vector<std::pair<std::string, long double>> related;
        int count = 0; 
        stringstream info(routes);
        while(getline(info, temp, ',')) {
            if(count == 3) {
                source_ID = temp;
            }
            if(count == 5) {
                dest_Id = temp;
            }
            count++;
        }
        // unsigned int source_lat =  stoi("1");
        // unsigned int source_long =  stoi("2");
        // unsigned int dest_lat =  stoi("3");
        // unsigned int dest_long =  stoi("4");
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
            cout << mappy[source_ID][0].first << endl;
        }else
        {
             mappy[source_ID].push_back(dest);
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

// Data structure to store adjacency list nodes
// struct Node
// {
//     int val, cost;
//     Node* next;
// };
 
// // Data structure to store a graph edge
// struct Edge {
//     int src, dest, weight;
// };
 
// class Graph
// {
//     // Function to allocate a new node for the adjacency list
//     Node* getAdjListNode(int value, int weight, Node* head)
//     {
//         Node* newNode = new Node;
//         newNode->val = value;
//         newNode->cost = weight;
 
//         // point new node to the current head
//         newNode->next = head;
 
//         return newNode;
//     }
 
//     int N;    // total number of nodes in the graph
 
// public:
 
//     // An array of pointers to Node to represent the
//     // adjacency list
//     Node **head;

//     Graph(const string& filename1, const string& filename2) { 
//         ifstream ifs(filename1);
//         string airport;
//         vector<string> airports;
    
//         if (ifs.is_open()) {
//             while (getline(ifs, airport)) {
//                 int count = 0;
//                 airports.clear();
//                 stringstream str(airport);
//                 while (getline(ifs, airport, ',')) {
//                     if (count == 4) {
//                         airports.push_back(airport);
//                     }
//                     count++;

//                 }

//             }
            
//         }

//         ifstream ifs2(filename2);
//         string dist;
//         if (ifs2.is_open()) {
//             while (getline(ifs2, dist)) {
                


//             }
//         }

//     }
 
//     // Constructor
//     Graph(Edge edges[], int n, int N) {

//         // allocate memory
//         head = new Node*[N]();
//         this->N = N;
 
//         // initialize head pointer for all vertices
//         for (int i = 0; i < N; i++) {
//             head[i] = nullptr;
//         }
 
//         // add edges to the directed graph
//         for (unsigned i = 0; i < n; i++)
//         {
//             int src = edges[i].src;
//             int dest = edges[i].dest;
//             int weight = edges[i].weight;
 
//             // insert at the beginning
//             Node* newNode = getAdjListNode(dest, weight, head[src]);
 
//             // point head pointer to the new node
//             head[src] = newNode;
 
//             // uncomment the following code for undirected graph
 
//             /*
//             newNode = getAdjListNode(src, weight, head[dest]);
 
//             // change head pointer to point to the new node
//             head[dest] = newNode;
//             */
//         }
//     }
 
//     // Destructor
//     ~Graph() {
//         for (int i = 0; i < N; i++) {
//             delete[] head[i];
//         }
 
//         delete[] head;
//     }
// };
 
// // Function to print all neighboring vertices of a given vertex
// void printList(Node* ptr, int i)
// {
//     while (ptr != nullptr)
//     {
//         cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
//         ptr = ptr->next;
//     }
//     cout << endl;
// }
 
// // Graph implementation in C++ without using STL
// int main()
// {
//     // an array of graph edges as per the above diagram
//     Edge edges[] =
//     {
//         // (x, y, w) —> edge from `x` to `y` having weight `w`
//         {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {4, 5, 1}, {5, 4, 3}
//     };
 
//     // total number of nodes in the graph (labelled from 0 to 5)
//     int N = 6;
 
//     // calculate the total number of edges
//     int n = sizeof(edges)/sizeof(edges[0]);
 
//     // construct graph
//     Graph graph(edges, n, N);
 
//     // print adjacency list representation of a graph
//     for (int i = 0; i < N; i++)
//     {
//         // print all neighboring vertices of a vertex `i`
//         printList(graph.head[i], i);
//     }
 
//     return 0;
// }


