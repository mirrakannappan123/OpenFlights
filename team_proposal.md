## Leading Question 
    We can learn about the different flight routes between various airports from the OpenFlights
    dataset. A specific issue that we are trying to resolve is finding the fastest possible route
    between two places. We do hope to produce a general search tool. We are planning to use BFS to
    traverse the dataset and then implement the Floyd-Warshall algorithm in order to find the
    shortest path between two locations. 

## Dataset Acquisition

    1. Data Format
    
    The source of the dataset is OpenFlights.org. The input format has airports and routes included
    for the datasets we are using. The dataset contains 67663 routes and 14,100 airports. We plan to
    use all of the dataset. 

    2. Data Correction
    For the dataset we will ensure to remove the Null values by using DataFram for C++ to load the
    dataset and ensuring the data is cleaned to be used by the BFS and Floyd–Warshall algorithm. We
    can drop empty row and column using the drop() menthod, and check for any outliers in the data
    by limiting the range of the location arguments and seeing whether they are valid on a map, if
    not we will remove it as well.

    3. Data Storage
    For the data structures we are planning on using Queues for storign the Vertices in Breath First
    Search algorithm. Which is overall O(V+E) time complexity and O(V) in space complexity.For the
    Floyd–Warshall algorithm we will be using Adjacency matrix to traverse a directed graph. The run
    time complexity is O(|n^3|) with a space complexity of O(|V^2|). For the A* search algorithm the
    run time complexity is O(b^d) where b is the branching factor, considering the goal state exists
    at all, and is reachable from the start state; if it is not, and the state space is infinite,
    the algorithm will not terminate.

## Algorithm 
    
    Function Inputs: The expected inputs for our algorithm is the names of the airports while the
    edges in the weighted graph will be the distance between the two airports for our weighted graph
    that will be stored in the adjacency matrix.

    Function Outputs : The expected output for our algorithm is the names of the airports which
    result in the fastest route between two places. We plan to visualize the outcome by showing the
    optimal route on a map. We are planning to use RStudio to do this. 
    
    Function Efficiency: For the BFS traversal we are targeting to reach a O(V + E) for a optimal
    time. For the Floyd-Warshall algorithm, we are targeting to reach a O(n^3) for a optial time.
    The target big O efficient for the Dijkstra’s algorithm is 0(v^2). 

## Timeline
    Week 0 (11/4): Finish the proposal and acquire the data
    Week 1 (11/11): Parse through the data and convert data into a weighted graph. Finish the graph
    class(entails finding the adjcency list using BFS algorithm).
    Week 2 (11/18): Implement Dijkstra’s Algorithm and start the A* search algorithm. 
    Week 3(11/25): Implement Floyd-Warshall Algorithm. 
    Week 4(12/2): Finish any lingering work and update READMe. Clean up code and documents. 
    Week 5(12/8): Film project deliverable
