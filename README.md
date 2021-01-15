# martianRoverNavigationSystem
Navigation system to find optimum paths for Martian rovers (ie- path with maximum research potential and one that does not exceeds given time constraints).

Maximising research in constrained time also ensures maximium research with minimum rover damage as less time => less locomotion => less wheel wear.

//Simulation of Martian surface:
The red planet will be simulated on a graph; with nodes as points with research potential ; edges as paths b/w those points with time required to travel through them as weights.

//System Input:
  //Map Entry(dynamic):
  -> Nodes research potential
  -> Egde weights (time required to travel b/w nodes)
  //Path finding Entry:
  -> Node1 (Starting point for rover)
  -> Node2 (Final point for rover)
  -> Time constraint (Max time available for traversal b/w Node1 and Node2)
  
 //System Output:
-> Optimum path if traversal possible in given time constraint / "No path possible"


Technology used:
-> Recursion and backtracking for finding optimum path.
-> (Optimisation)Floyd Warshall's Algorithm, timeComplexity: O(V^3).... called only once after complete map entry to compute minimum time b/w all pair of nodes. //System works without this optimization as well.
