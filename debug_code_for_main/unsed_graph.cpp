// void Graph::dijkstraShortestPathh(Vertex start_airport, Vertex dest_airport) {
//     for(auto key_pair: cost)
//    {
//         cout<< "source vertex: " << key_pair.first<< " ";
//         for(auto value: adjacency_list[key_pair.first])
//         {
//             cout << "dest: " << value.first << " how far:" << value.second.getWeight()<< endl;
//         }
//    }
    // auto cost = getAdjList();

//     int src = VtIforDij[start_airport];
//     vector<int>pred(adjacency_list.size(), src);
//     priority_queue<diPair, vector<diPair>, greater<diPair>> pq;  
//     vector<double> dist(adjacency_list.size(), INF); // All distance from source are infinite  
//     pq.push(make_pair(0.0, src)); // push spurce node into the queue  
//     dist[src] = 0.0; // distance of source will be always 0  
//     while (!pq.empty()) { // While queue is not empty  
//         // Extract the first minimum distance from the priority queue  
//         // vertex label is stored in second of pair (it  
//         // has to be done this way to keep the vertices  
//         // sorted distance 
//         int u = pq.top().second;  
//         pq.pop();  
//         // 'i' is used to get all adjacent vertices of a vertex  
//         list<pair<int, double>>::iterator i;  
//         // cout << "REACHLINE" << endl;
//         for (i = adj[u].begin(); i != adj[u].end(); ++i) {  
//             // Get vertex label and weigh of current adjacent  
//             // of u.  
//             // cout << "REACHLINE" << endl;
//             int v = (*i).first;  
//             double weight = (*i).second;  
//             // cout << v << " " << weight << endl;
//             // If there is shorted path to v through u.  
//             if (dist[v] > dist[u] + weight) {  
//                 // Updating distance of v  
//                 dist[v] = dist[u] + weight;  
//                 pq.push(make_pair(dist[v], v)); 
//                 pred[v]=u; 
//             }  
//         }  
//     }  
//     printf("Vertex \tDistance from Source \t Path\n"); // Print the result  
//     for (int i = 0; i < int(adjacency_list.size()); ++i)
//     {
//             if(i != src)
//             { 
//                 printf("%s \t\t %f \t", ItVforDij[i].c_str(), dist[i]); // The shortest distance from source
//                 printf("\nPath=%s",ItVforDij[i].c_str()); 
//                 int j = i;
//                 while(j != src)
//                 {
//                     j = pred[j];
//                     printf("<-%s",ItVforDij[j].c_str());
//                 }
//                 printf("\n");
//             }
//     }  
//     cout << dest_airport << endl;
// }

// // Calling function outside the Graph class  
// void Graph::shortestPathingraph(int src) // src is the source vertex  
// {  
//     // Create a priority queue to store vertices that  
//     // are being preprocessed.  
//     priority_queue<iPair, vector<iPair>, greater<iPair>> pq;  
//     vector<double> dist(V, INF); // All distance from source are infinite  
//     pq.push(make_pair(0.0, src)); // push spurce node into the queue  
//     dist[src] = 0.0; // distance of source will be always 0  
//     while (!pq.empty()) { // While queue is not empty  
//         // Extract the first minimum distance from the priority queue  
//         // vertex label is stored in second of pair (it  
//         // has to be done this way to keep the vertices  
//         // sorted distance  
//         int u = pq.top().second;  
//         pq.pop();  
//         // 'i' is used to get all adjacent vertices of a vertex  
//         list<pair<int, double>>::iterator i;  
//         for (i = adj[u].begin(); i != adj[u].end(); ++i) {  
//             // Get vertex label and weight of current adjacent  
//             // of u.  
//             int v = (*i).first;  
//             double weight = (*i).second;  
  
//             // If there is shorted path to v through u.  
//             if (dist[v] > dist[u] + weight) {  
//                 // Updating distance of v  
//                 dist[v] = dist[u] + weight;  
//                 pq.push(make_pair(dist[v], v));  
//             }  
//         }  
//     }  
//     printf("Vertex \tDistance from Source\n"); // Print the result  
//     for (int i = 0; i < V; ++i)  
//         printf("%d \t\t %f\n", i, dist[i]); // The shortest distance from source  
// } 



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