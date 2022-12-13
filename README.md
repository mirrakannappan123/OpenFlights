# 225_Final_Project - Open Flights 

## Group Members: 
- mirrak2
- deevyas2
- huiyaol2
- jayshri2

## Overview 
Our project looks that OpenFlight data set from: https://openflights.org/data.html. From this data, we created a weighted and directed graph with the airport ID's as the Vertex and the distance between each airport as the edge. Our goal for this project was to produce a general search tool that allows an user to find the shortest path between two destinations (airports). 

To achieve this goal we implemented the Floyd-Warshall Algorithm, the Dijkstra Alogrithm, iterative DFS, and DFS to traverse and output the data.

## Usage
For the test cases, execute the following command: 

    $ make tests
    $ ./bin/tests - runs all the test cases 
    $ ./bin/tests "test case name" - runs a selected test case

To actually find out the shortest distance between two airports, run the following commands: 

    



