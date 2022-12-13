# 225_Final_Project - Open Flights 

## Group Members: 
- mirrak2
- deevyas2
- huiyaol2
- jayshri2

## Overview 
Our project looks that OpenFlight data set from: https://openflights.org/data.html. From this data, we created a weighted and directed graph with the airport ID's as the Vertex and the distance between each airport as the edge. Our goal for this project was to produce a general search tool that allows an user to find the shortest path between two destinations (airports). 

Here is our presentation video: https://youtu.be/uBApWAYBcTI

To achieve this goal we implemented the Floyd-Warshall Algorithm, the Dijkstra Alogrithm, iterative deepening DFS, and DFS to traverse and output the data.

## Running the Tests
For the test cases, execute the following command: 

    $ make tests
    $ ./bin/tests - runs all the test cases 
    $ ./bin/tests "test case name" - runs a selected test case


## Organization 
### Graph.h and Graph.cpp
This file assists in creating the weighted and directed graph used in main.cpp and in our algorithms. This file also contains our iterative deepening DFS(IDDFS), DFS, and Djistraka Algorithm. 

The Djstrka Algorithm outputs the shortest path and the distance it from the source to the destination. While DFS prints which node it traversed through in the dfs_output.txt file and IDDFS prints which node it traversed through in the iddfs_output.txt file. 

### Floyd.h and Floyd.cpp
This file is dedicated to implementing the Floyd-Warshall algorithm. To Note: the run time for the algorithm is O(N^3) so it takes a really long time to output the path. This algorithm outputs a vector of airport ID's which ultimately is the shortest path. 

### Parse.h and Parse.cpp
This file parses through the openflights data and cleans the data as its parsing. 

### LatLong.cpp
This file calulates the distance given the latitutde and longitude. 

### main.cpp
This file is main executable file that will allow the user to input the two airport ID's to find the shortest path. 

## Usage (Running our code)
For running the program, execute the following command: 

    $ make exec
    $ ./bin/exec - runs main.cpp
    
You will be prompted to enter the source Airport ID and the Destination Airport ID which will run the algorithms.
