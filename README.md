# Martian Rover Navigation System
Navigation system to find optimum paths for Martian rovers(ie- Path with maximum research potential and one that does not exceeds the query time budget).

Simulation of Martian surface: Connected weighted graph.
- Vertex weight -> Research potential of vertex;
- Edge weight -> Time to travel through edge.

Model Input:    
  - Map Entry(dynamic):   
     - Vertex x-coordinates, Vertex weights.
     - Edge weights
  - Path query inputs:
    - Vertex 1 (Starting point for rover)
    - Vertex 2 (Destination for rover)
    - Time Budget (Maximum time available for traversal b/w Vertex 1 and Vertex 2) 
  
Model Output:
   - Optimum path if traversal is possible in the given time constraint / "No path possible"

Technology used:
  - Depth first search with memorisation(Dynamic Programming).
  - A Star Algorithm.


Project PPT: [PPT](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/NavMars_SystemPPT.pdf)

Source Code (Optimized DP Version): [Code](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/NavMars%20_withDPOptimisation.cpp)

Sample Graph: [Graph](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/SampleGraph.jpeg)

Source Code (Backtracking Version) : [Code](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/navigationSystem.cpp)

Model Tests (Backtracking Version) : [Tests](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/ModelTests.ipynb)

Project report (Backtracking version): [Report](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/Project%20Report%20(Backtracking%20Version).pdf)
