#include "graph.h"


Graph::Graph(bool weighted) {
   weight = weighted; 
    direct = false; 
}

Graph::Graph(bool weighted, bool directed){
    weight= weighted; 
    direct = directed; 
}
Graph::Graph(bool weighted, bool directed, map<string,vector<pair<string, long double>>> map)
{
    weight= weighted; 
    direct = directed;

    for(auto source: map)
    {
        if(!assertVertexExists(source.first, "constructo"))insertVertex(source.first);
        for(auto dest: source.second)
        {
            if(!assertVertexExists(dest.first,"constructor"))insertVertex(dest.first);
            insertEdge(source.first, dest.first);
            if (weighted)setEdgeWeight(source.first, dest.first, dest.second);
        }
    }
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
    std::set<pair<Vertex, Vertex>> seen;

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
                if(!direct)
                {
                    seen.insert(make_pair(destination, source));
                }
            }
        }
    }

    return ret;
}

// Edge Graph::setEdgeLabel(Vertex source, Vertex destination, string label) {
//     if (assertEdgeExists(source, destination, __func__) == false)
//         return InvalidEdge;
//     Edge e = adjacency_list[source][destination];
//     Edge new_edge(source, destination, e.getWeight(), label);
//     adjacency_list[source][destination] = new_edge;

//     if(!directed)
//     {
//         Edge new_edge_reverse(destination,source, e.getWeight(), label);
//         adjacency_list[destination][source] = new_edge_reverse;
//     }
//     return new_edge;
// }

// string Graph::getEdgeLabel(Vertex source, Vertex destination) {
//     if(assertEdgeExists(source, destination, __func__) == false)
//         return InvalidLabel;
//     return adjacency_list[source][destination].getLabel();
// }

double Graph::getEdgeWeight(Vertex source, Vertex destination) const {
    if (!weight)
        error("can't get edge weights on non-weighted graphs!");

    return adjacency_list[source][destination].getWeight();
}
void Graph::insertVertex(Vertex v) {
    // make it empty again
    adjacency_list[v] = unordered_map<Vertex, Edge>();
}


void Graph::insertEdge(Vertex source, Vertex destination) {
    if(adjacency_list.find(source)!= adjacency_list.end() 
    && adjacency_list[source].find(destination)!= adjacency_list[source].end())
    {
        //edge already exit
        return ;
    }

    if(adjacency_list.find(source)==adjacency_list.end())
    {
        adjacency_list[source] = unordered_map<Vertex, Edge>();
    }
        //source vertex exists
    adjacency_list[source][destination] = Edge(source, destination);
    if(!direct)
    {
        if(adjacency_list.find(destination)== adjacency_list.end())
        {
            adjacency_list[destination] = unordered_map<Vertex, Edge>();
        }
        adjacency_list[destination][source] = Edge(source, destination);
    }
}

void Graph::setEdgeWeight(Vertex source, Vertex destination, double weight) {
    if (assertEdgeExists(source, destination, __func__) == false)
        return;;
    Edge e = adjacency_list[source][destination];
    //std::cout << "setting weight: " << weight << std::endl;
    Edge new_edge(source, destination, weight, e.getLabel());
    adjacency_list[source][destination] = new_edge;

    if(!direct)
        {
            Edge new_edge_reverse(destination,source, weight, e.getLabel());
            adjacency_list[destination][source] = new_edge_reverse;
        }

    return;
}

bool Graph::assertVertexExists(Vertex v, string functionName) const
{
    if (adjacency_list.find(v) == adjacency_list.end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent vertices");
        return false;
    }
    return true;
}

bool Graph::assertEdgeExists(Vertex source, Vertex destination, string functionName) const {
    if(assertVertexExists(source,functionName) == false)
        return false;
    if(adjacency_list[source].find(destination)== adjacency_list[source].end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent edge " + source + " -> " + destination);
        return false;
    }

    if(!direct)
    {
        if (assertVertexExists(destination,functionName) == false)
            return false;
        if(adjacency_list[destination].find(source)== adjacency_list[destination].end())
        {
            if (functionName != "")
                error(functionName + " called on nonexistent edge " + destination + " -> " + source);
            return false;
        }
    }
    return true;
}

void Graph::error(string message) const {
    cerr << "\033[1;31m[Graph Error]\033[0m " + message << endl;
}


/**
 * Prints the graph to stdout.
 */
void Graph::print() const
{
    for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) 
    {
        cout << it->first << endl;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) 
        {
            std::stringstream ss;
            ss << it2->first; 
            string vertexColumn = "    => " + ss.str();
            vertexColumn += " " ;
            cout << std::left << std::setw(26) << vertexColumn;
            string edgeColumn = "edge label = \"" + it2->second.getLabel()+ "\"";
            cout << std::left << std::setw(26) << edgeColumn;
            if (weight)
                cout << "weight = " << it2->second.getWeight();
            cout << endl;
        }
        cout << endl;
    }
}

std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> Graph::getAdjList() {
    return adjacency_list;
}


void Graph::dijkstraShortestPathh(Vertex start_airport, Vertex dest_airport) {

    double infi = numeric_limits<double>::infinity();
//     Vertex startnode = start_airport, nextnode;
//     int count = 1;
//     double mindistance;
//     auto cost = getAdjList();
//     map<Vertex,double> distance;
//     map<Vertex, bool> visited; 
//     map<Vertex, Vertex>pred;
//     // int cost[MAX][MAX],distance[MAX],pred[MAX];
//     // int count,mindistance,nextnode,i,j;
//     // vector<string>
//     //pred[] stores the predecessor of each node
//     //count gives the number of nodes seen so far
//     //create the cost matrix
//     // for(i=0;i<n;i++)
//     // for(j=0;j<n;j++)
//     // if(G[i][j]==0)
//     //     cost[i][j]=infi;
//     // else
//     // cost[i][j]=G[i][j];
//     // //initialize pred[],distance[] and visited[]

//     // auto cost = getAdjList();
//     // map distance, 
// //    for(auto key_pair: cost)
// //    {
// //     cout<< "source vertex: " << key_pair.first<< " ";
// //     for(auto value: key_pair.second)
// //     {
// //         cout << "dest: " << value.first << " how far:" << value.second.getWeight()<< endl;
// //     }
// //    }
//     for(auto key_pair: cost[startnode])
//     {
//         if(key_pair.second.getWeight() == -1) continue;
//         distance.insert({key_pair.first, key_pair.second.getWeight()});
//         pred[key_pair.first] = startnode;
//         visited[key_pair.first] = 0;
//         // cout << key_pair.first << " dis: " << key_pair.second.getWeight();
//     }
//     // for(i=0;i<n;i++)
//     // {
//     //     distance[i]=cost[startnode][i];
//     //     pred[i]=startnode;
//     //     visited[i]=0;
//     // }
//     distance[startnode] = 0.0;
//     visited[startnode] = 1;
//     while(count<total_airpots-1)
//     {
//         mindistance=infi;
//     //nextnode gives the node at minimum distance
//         for(auto key: cost)
//         {
//             if(distance.count(key.first) && distance[key.first]<mindistance&&!visited[key.first])
//             {
//                 mindistance=distance[key.first];
//                 nextnode= key.first;
//             }
//             visited[nextnode]=1;
//             for(auto key: cost)
//             {
//                 if(!visited[key.first])
//                 {
//                     if(cost[nextnode][key.first].getWeight()!= -1 && (mindistance+cost[nextnode][key.first].getWeight())<distance[key.first])
//                     {
//                         // cout << "min in loop" << mindistance <<" cost" << cost[nextnode][key.first].getWeight() << endl;
//                         distance[key.first] = mindistance+cost[nextnode][key.first].getWeight();
//                         // cout << "dis in loop" << distance[key.first] << endl;
//                         pred[key.first]=nextnode;
//                     }
//                 }
//             }

//         }
//         count++;
//     }
//     //print the path and distance of each node
//     // for(auto key: cost)
//     // {
//     //     if(key.first!=startnode)
//     //     {
//     //         cout << "\nDistance of node " << key.first << " = " << distance[key.first]<<endl;
//     //         cout << "\nPath= " << key.first;
//     //         Vertex j=key.first;
//     //         do
//     //         {
//     //             j=pred[j];
//     //             cout<< " <-"<< j;
//     //         }while(j!=startnode);
//     //     }
//     // }
//       for(auto key: cost)
//     {
//         if(key.first!=startnode)
//         {
//             cout << "\nDistance of node " << key.first << " = " << distance[key.first]<<endl;
//             cout << "\nPath= " << key.first;
//             // Vertex j=key.first;
//             // do
//             // {
//             //     j=pred[j];
//             //     cout<< " <-"<< j;
//             // }while(j!=startnode);
//         }
//     }
    auto cost = getAdjList();
//     for(auto key_pair: cost)
//    {
//         cout<< "source vertex: " << key_pair.first<< " ";
//         for(auto value: adjacency_list[key_pair.first])
//         {
//             cout << "dest: " << value.first << " how far:" << value.second.getWeight()<< endl;
//         }
//    }
    map<Vertex,double> distance;
    map<Vertex, bool> visited; 
    // map<Vertex, Vertex>pred;
    priority_queue<sdPair, vector<sdPair>, greater<sdPair>> pq;  
    for(auto key_pair: cost[start_airport])
    {
        distance.insert({key_pair.first, infi});
        // pred[key_pair.first] = start_airport;
        visited[key_pair.first] = 0;
        // cout << key_pair.first << " dis: " << key_pair.second.getWeight();
    } // All distance from source are infinite  
    pq.push(make_pair(start_airport, 0.0)); // push spurce node into the queue  
    distance[start_airport] = 0; // distance of source will be always 0  
    while (!pq.empty()) { // While queue is not empty  
        // Extract the first minimum distance from the priority queue  
        // vertex label is stored in second of pair (it  
        // has to be done this way to keep the vertices  
        // sorted distance  
        string u = pq.top().first;  
        pq.pop();  
        // 'i' is used to get all adjacent vertices of a vertex  
        list<pair<string, double>>::iterator i;  
        for (auto i = adjacency_list[u].begin(); i != adjacency_list[u].end(); ++i) {  
            // Get vertex label and weight of current adjacent  
            // of u.  
            Vertex v = (*i).first;  
            double weight = (*i).second.getWeight();  
            // If there is shorted path to v through u.  
            if (!visited[v] &&distance[v] > distance[u] + weight) {  
                // Updating distance of v  
                distance[v] = distance[u] + weight;  
                pq.push(make_pair(v, distance[v]));
                visited[v] = 1;
            }  
        }  
    }  
    printf("Vertex \tDistance from Source\n"); // Print the result  
    for(auto v: getVertices())
    {
        if(v != start_airport)printf("%s \t\t %f\n",v.c_str(), distance[v]); // The shortest distance from source  
    }
    cout<<dest_airport << endl;
}
