# martianRoverNavigationSystem
Navigation system to find optimum paths for Martian rovers (ie- path with maximum research potential and one that does not exceeds given time constraints).

//Simulation of Martian surface:
The red planet has been simulated using a connected weighted graph (both vertices and edges have weights).
Vertex weight -> Research potential of vertex;
Edge weight -> Time to travel through edge.

//Model Input:    
  - Map Entry(dynamic):   
     - Vertex research potential
     - Edge weights   
  - Path query inputs:
  -> Vertex 1 (Starting point for rover)
  -> Vertex 2 (Destination for rover)
  -> Time constraint (Maximum time available for traversal b/w Node1 and Node2) 
  
//Model Output:
  -> Optimum path if traversal is possible in given time constraint / "No path possible"


Technology used:
-> Recursion and backtracking to find optimum path.
-> (Optimisation)Floyd Warshall's Algorithm (to cache minimum time of traversal b/w all pair of vertices) // Model can run successfully without this cached data as well.

//Model flow chart: https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/systemFlowChart.png

//Model Tests: https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/GUI.ipynb 

//Detailed Project Report: https://github.com/its7ARC/martianRoverNavigationSystem/blob/main/projectReport.pdf
