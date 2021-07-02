# Martian Rover Navigation System
Navigation system to find optimum paths for Martian rovers (ie- path with maximum research potential and one that does not exceeds given time constraints).

Simulation of Martian surface:
The red planet has been simulated using a connected weighted graph (both vertices and edges have weights).
- Vertex weight -> Research potential of vertex;
- Edge weight -> Time to travel through edge.

Model Input:    
  - Map Entry(dynamic):   
     - Vertex x-coordinates, weights.
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


Model PPT: [PPT](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/NavMars_SystemPPT.pdf)

Sample Graph: [Graph](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/SampleGraph.jpeg)

Model Tests: [Tests](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/ModelTests.ipynb)

Detailed Project Report: [Report](https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/ADA_Report.pdf)
