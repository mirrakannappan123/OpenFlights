#include "graph.h"


Graph::Graph(bool weighted) {
   weight = weighted; 
    direct = false; 
}

Graph::Graph(bool weighted, bool directed){
    weight= weighted; 
    direct = directed; 
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

void Graph::initSnapshot(string title)
{
    picNum = 0;
    picName = title;
}

/**
 * Saves a snapshot of the graph to file.
 * initSnapshot() must be run first.
 */
void Graph::snapshot()
{
    std::stringstream ss;
    ss << picNum;
    string newName = picName + ss.str();
    //savePNG(newName);
    ++picNum;
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

void Graph::printDFS(){
  std::ofstream outFile("dfs_output.txt");
  outFile << "Generated DFS Traversal of airport IDs: " << std::endl;
//   std::cout << "path size" << path.size() << std::endl;
  for(auto itr = path.begin(); itr != path.end(); ++itr) {
    outFile << *itr << std::endl;
  }
  outFile << "End of traversal";
  outFile.close();
}

std::vector<Vertex> Graph::dfs(){
  path.clear();
  visited.clear();
  for(auto airport_pair : adjacency_list){
    dfs(airport_pair.first);
  }
  return path;
}

std::vector<Vertex> Graph::dfs(Vertex src_airport){
  if(visited.find(src_airport) != visited.end()){
    return {};
  }
  visited.insert(src_airport);
  path.push_back(src_airport);
  std::vector<Vertex> dest_airports;
  for(auto element : adjacency_list[src_airport]){
    dest_airports.push_back(element.first);
  }
  for(size_t i = 0; i < adjacency_list[src_airport].size(); i++){
    if(visited.find(dest_airports[i]) == visited.end()){
        // std::cout << "dest airport " << dest_airports[i] << std::endl;
      dfs(dest_airports[i]);
    }
  }
  printDFS();
  return path;
}

// Iterative deepening dfs
std::vector<Vertex> Graph::IDDFS(Vertex src, Vertex target, int max_depth) {
    // Repeatedly depth-limit search till the maximum depth.
    path.clear();
    visited.clear();
    for (int i = 0; i <= max_depth; i++) {
       if (DLS(src, target, i) == true) {
         return path;

       }
    }
    return {};
}

bool Graph::DLS(Vertex src, Vertex target, int limit) {
    path.push_back(src);
    if(visited.find(src) != visited.end()){
        return false;
    }
    if (src == target)
        return true;
    if (limit <= 0)
        return false;
    visited.insert(src);
    std::vector<Vertex> dest_airports;
    for(auto element : adjacency_list[src]){
        dest_airports.push_back(element.first);
    }
    for(size_t i = 0; i < adjacency_list[src].size(); i++){   
        if (DLS(dest_airports[i], target, limit - 1) == true) {
            
            return true;
        }
    }
    printIDDFS();
    return false;
}

void Graph::printIDDFS() {
    std::ofstream outFile("iddfs_output.txt");
    outFile << "Generated IDFFS Traversal of airport IDs: " << std::endl;
    //   std::cout << "path size" << path.size() << std::endl;
    for(auto itr = path.begin(); itr != path.end(); ++itr) {
        outFile << *itr << std::endl;
    }
    outFile << "End of traversal";
    outFile.close();

}


void Graph::dijkstraShortestPathh(Vertex start_airport, Vertex dest_airport) {

    double infi = numeric_limits<double>::infinity();

    auto cost = getAdjList();
    map<Vertex,double> distance;
    map<Vertex, bool> visited; 
    priority_queue<sdPair, vector<sdPair>, greater<sdPair>> pq;  
    for(auto key_pair: cost[start_airport])
    {
        distance.insert({key_pair.first, infi});
        // pred[key_pair.first] = start_airport;
        visited[key_pair.first] = 0;
    } // All distance from source are infinite  
    pq.push(make_pair(start_airport, 0.0)); // push spurce node into the queue  
    distance[start_airport] = 0; // distance of source will be always 0  
    while (!pq.empty()) { // While queue is not empty  
        string u = pq.top().first;  
        pq.pop();  
        // 'i' is used to get all adjacent vertices of a vertex  
        list<pair<string, double>>::iterator i;  
        for (auto i = adjacency_list[u].begin(); i != adjacency_list[u].end(); ++i) {  
            Vertex v = (*i).first;  
            double weight = (*i).second.getWeight();  
            if (!visited[v] &&distance[v] > distance[u] + weight) {  
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


