# 225_Final_Project

## Team Contract
Communication
Team Meetings : All team meetings will be in person at 4th floor grainger every week for 1-2 hours on Wednesday. We will not be recording our meetings.
Assistance : We will be contacting each other through text messages. We will be expected to respond to each other by the end of the day.
Respect : We will make sure all team members are able to voice their opinions when discussing project ideas. We must come to a full agreement on ideas related to the project.
Collaboration
Work Distribution : We will split up the workload based on our goals and each of our strengths for each week. We will make sure each group member has a part to work on for the project. We will come together and discuss any unexpected complications. If needed, we will contact our mentor.

Time Commitment : Each team member must spend at minimum 3 to 4 hours a week on their assigned task or up unitl that task is completed. If a team member is unable to commit time to complete thier task they must let the other team members know and complete it by the next week. If conflicts do arise, we will come to a conclusion as a group and move deadlines as needed.

Conflict Resolution Our team will resolve situations where there is a disagreement by talking it out and coming to a middle ground. We will give members a few warnings if they have not accomplished their tasks. Although, if this behavior continues, we will address the problem with our mentor. We will address members being late with the same process. No, there are no other hypothetical situations that we want to discuss ahead of time.

Signatures
Jayshri Ganguly
Deevya Swain
Mirra Kannappan
Huiyao Liang

## Project Proposal

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
