#include "graph.h"


Graph::Graph(bool weighted) {
   weight = weighted; 
    direct = false; 
}

Graph::Graph(bool weighted, bool directed){
    weight= weighted; 
    direct = directed; 
}
Graph::Graph(bool weighted, bool directed, map<string,vector<pair<string, long double>>> map, int total_airlines)
{
    weight= weighted; 
    direct = directed;
    adj = new list<pair<int, double>>[total_airlines];
    int count = 0;
    for(auto source: map)
    {
        Vertex s(source.first);
        if(!assertVertexExists(s, ""))
        {
            insertVertex(s);
            VtIforDij[source.first] = count;
            ItVforDij[count] = source.first;
            count++;
        }
        for(auto dest: source.second)
        {
            Vertex d(dest.first);
            if(!assertVertexExists(d,""))
            {
                insertVertex(d);
                VtIforDij[dest.first] = count;
                ItVforDij[count] = dest.first;
                count++;
            }
            insertEdge(s, d);
            if (weighted)setEdgeWeight(s, d, dest.second);
            addEdge(VtIforDij[source.first], VtIforDij[dest.first], dest.second);
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
    if(assertEdgeExists(source, destination,"") == false)
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
    if (assertEdgeExists(source, destination, "") == false)
        return;
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
        // if (functionName != "")
        //     error(functionName + " called on nonexistent edge " + source + " -> " + destination);
        return false;
    }

    if(!direct)
    {
        if (assertVertexExists(destination,functionName) == false)
            return false;
        if(adjacency_list[destination].find(source)== adjacency_list[destination].end())
        {
            // if (functionName != "")
            //     error(functionName + " called on nonexistent edge " + destination + " -> " + source);
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
void Graph::printPath(Path input) const
{
    vector<Vertex> temp = input.path_;
    int last = temp.size();
    if(last == 0)
    {
        cout<< "no matched airlines"<<endl; ;
        return;
    
    }
    Vertex dest = temp[last-1];
    printf("Dest \t Path\n"); // Print the result   
    printf("%s\t ", dest.c_str()); // The shortest distance from source
    for(Vertex v: temp)
    {
        if(v != dest)printf("%s->",v.c_str());
        else printf("%s",v.c_str());
    }
    cout<<endl;  
}

std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> Graph::getAdjList() 
{
    return adjacency_list;
}

void Graph::addEdge(int u, int v, double w) // add an edge  
{  
    if(direct)adj[u].push_back(make_pair(v, w)); // make a pair of vertex and weight and // add it to the list
    else
    {
        adj[u].push_back(make_pair(v, w)); // make a pair of vertex and weight and // add it to the list  
        adj[v].push_back(make_pair(u, w)); // add oppositely by making a pair of weight and vertex  
    }  
}  

Path Graph::dijkstraShortestPath(Vertex start_airport, Vertex dest_airport) {
    int src = VtIforDij[start_airport];
    int dest = VtIforDij[dest_airport];
    Path output;
    if(!adjacency_list.count(start_airport) || !adjacency_list.count(dest_airport))
    {
        output.path_ = vector<Vertex>{};
        output.dist_ = 0.0; 
        return output;
    }

    vector<int>pred(adjacency_list.size(), src);

    priority_queue<diPair, vector<diPair>, greater<diPair>> pq;  
    vector<double> dist(adjacency_list.size(), INF); // All distance from source are infinite  
    pq.push(make_pair(0.0, src)); // push spurce node into the queue  
    dist[src] = 0.0; // distance of source will be always 0 
    
    while (!pq.empty()) 
    { // While queue is not empty  
        // Extract the first minimum distance from the priority queue  
        // vertex label is stored in second of pair (it  
        // has to be done this way to keep the vertices  
        // sorted distance 
        int u = pq.top().second;  
        pq.pop();  
        // 'i' is used to get all adjacent vertices of a vertex  
        list<pair<int, double>>::iterator i;  
        // cout << "REACHLINE" << endl;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {  
            // Get vertex label and weigh of current adjacent  
            // of u.  
            int v = (*i).first;  
            double weight = (*i).second;  
            // cout << v << " " << weight << endl;
            // If there is shorted path to v through u.  
            if (dist[v] > dist[u] + weight) {  
                // Updating distance of v  
                dist[v] = dist[u] + weight;  
                pq.push(make_pair(dist[v], v)); 
                pred[v]=u; 
            }  
        }  
    }
    
    stack<Vertex> temp;
    output.dist_= dist[dest];  
    int j = dest;
    temp.push(ItVforDij[j]);
    while(j != src)
    {
        j = pred[j];
        temp.push(ItVforDij[j]);
    }
    while(!temp.empty())
    {
        output.path_.push_back(temp.top());
        temp.pop();
    }
    return output;
}