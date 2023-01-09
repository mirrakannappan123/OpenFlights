// vector<Edge> edges = g.getEdges();
    // cout<< "Source Vertex: \t Dest: \t Dis: "<<endl;
    // for(auto src: edges)
    // {
    //     cout<< src.source<<"\t" << src.dest << "\t" << src.getWeight()<<endl;;
    // }
    // cout<<"994"<<"\t" << "2179" << "\t";
//    for(auto ele: map["994"])
//    {
//         if(ele.first == "2179")
//         {
//             cout<<ele.second<<endl;
//         }
//         //  cout<<ele.first<<endl;
//    }
    // auto ha = g.getAdjacent("994");
    // for(auto ele: ha) cout<<ele<<endl;
//    auto a = g.getAdjList();
//    cout<<a["994"]["2179"].getWeight()<<endl;
//    for(auto src: map)
//     {
//         Vertex s (src.first);
//         for(auto dest_map: src.second)
//         {
//             Vertex d(dest_map.first);
//             cout<< s<<"\t" << d << "\t" << g.getEdge(s, d).getWeight()<<endl;;
//         }
//     }
    
// void display_AdjList(adjNode* ptr, int i)
// {
//     while (ptr != nullptr) {
//         cout << "(" << i << ", " << ptr->val
//             << ", " << ptr->cost << ") ";
//         ptr = ptr->next;
//     }
//     cout <<endl;
    // cout << "cout" << endl;
    // std::vector<Vertex> test = temp.getGraph().getAdjacent(); 

    
    //std::cout<<temp.getGraph().getAdjacent(664)<<std::endl;
    // for(auto route: map){
    //     //std::cout<<"in the loop"<<std::endl;
    //     for(auto adj: route.second){
    //         std::cout<<route.first<<std::endl;
    //         std::vector<Vertex> test = temp.getGraph().getAdjacent(route.first); 
    //         //std::cout << "(" << route.first << ", " << adj.first << ", " << adj.second << " )" << std::endl;
    //         for(size_t i = 0; i < test.size(); i++) {
    //             std::cout << test[i] <<std::endl;
    //         }
    //         break;
    //     }
    //     break;
    // }
    // cout << "cout" << endl;

   // for(auto key_pair: map)
   // {
   //  cout<< "source vertex: " << key_pair.first<< " ";
   //  for(auto value: key_pair.second)
   //  {
   //      cout << "dest: " << value.first << " how far:" << value.second<< endl;
   //  }
   // }



   //   g.insertVertex("airport0");
   //   g.insertVertex("airport1");
   //   g.insertVertex("airport2");
   //   g.insertVertex("airport3");
   //   g.insertVertex("airport4");

   //   g.insertEdge("airport0","airport1");
   //   g.setEdgeWeight("airport0","airport1", 10.5);
   //   g.insertEdge("airport0","airport4");
   //   g.setEdgeWeight("airport0","airport4", 100.5);
   //   g.insertEdge("airport0","airport3");
   //   g.setEdgeWeight("airport0","airport3", 30.5);
   //   g.insertEdge("airport1","airport2");
   //   g.setEdgeWeight("airport1","airport2", 50.5);
   //   g.insertEdge("airport2","airport3");
   //   g.setEdgeWeight("airport2","airport3", 20.5);
   //   g.insertEdge("airport3","airport4");
   //   g.setEdgeWeight("airport3","airport4", 60.5);
   //   g.insertEdge("airport2","airport4");
   //   g.setEdgeWeight("airport2","airport4", 10.5);


   //    std::map<string, std::vector<std::pair<std::string, long double>>> map {
   //      {"0",{{"1", 10.5}, {"4", 100.5}, {"3", 30.5}}},
   //      {"1", {{"0", 10.5}, {"2", 50.5}}},
   //      {"2", {{"1", 50.5}, {"4", 10.5}, {"3", 20.5}}},
   //      {"3", {{"2", 20.5}, {"0", 30.5}, {"4", 60.5}}},
   //      {"4", {{"3", 60.5}, {"2", 10.5}, {"0",100.5}}}
   //   };
   //    std::map<string, std::vector<std::pair<std::string, long double>>> map {
   //      {"airport0",{{"airport1", 10.5}, {"airport4", 100.5}, {"airport3", 30.5}}},
   //      {"airport1", {{"airport0", 10.5}, {"airport2", 50.5}}},
   //      {"airport2", {{"airport1", 50.5}, {"airport4", 10.5}, {"airport3", 20.5}}},
   //      {"airport3", {{"airport2", 20.5}, {"airport0", 30.5}, {"airport4", 60.5}}},
   //      {"airport4", {{"airport3", 60.5}, {"airport2", 10.5}, {"airport0",100.5}}}
   //   };
      //  Graph g (true, false, map);
      //  g.dijkstraShortestPath("airport0", "airport4");

      //  Graph g (true, false, map);
      //  Vertex src = "airport0", dest = "airport2";
      //  g.printPath( g.dijkstraShortestPath(src, dest));

      // Floyd f(g);
      // vector<string> output = f.shortestPath("airport0", "airport4");
      // for(auto ele: output) cout << ele << endl;

   //  int V = 5; // vertices in given graph are 9  
   //  Graph g(V); //  call Constructor by creating an object of graph  
   //  g.addEdge(0, 1, 10.5); // add root node with neighour vertex and weight  
   //  g.addEdge(0, 4, 100.5);  
   //  g.addEdge(0, 3, 30.5);  
   //  g.addEdge(1, 2, 50.5);  
   //  g.addEdge(2, 4, 10.5);  
   //  g.addEdge(2, 3, 20.5);  
   //  g.addEdge(3, 4, 60.5);
   //  g.shortestPathingraph(0);