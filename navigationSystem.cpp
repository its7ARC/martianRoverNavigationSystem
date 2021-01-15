
//Navigation System for martian rovers

/*Sample Graph(image shown in sampleGraph.png)
//forTesting
 //Adding nodes and edgeWts
 1 0 1 4
 1 0 2 3
 1 1 3 7
 1 3 4 5
 1 2 5 7
 1 0 6 8
 1 4 7 10
 1 4 5 5
 1 5 7 7
 1 6 7 2
 1 6 8 5
 
 //adding research potential of nodes
 2 0 10
 2 1 15
 2 2 15
 2 3 12
 2 4 20
 2 5 30
 2 6 40
 2 7 100
 
 //adding more nodes
 1 0 9 2
 1 9 10 2
 1 10 7 1
 //assigning research potential to newly added nodes
 2 8 10
 2 9 5
 2 10 7
 
*/


#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#define MAX 10000
using namespace std;

void line(){
    for(int i = 0; i < 30; i++){
        cout << "--";
    }
    cout << "\n";
}

class Graph{
    int V = 0;
    unordered_map<int, list<pair<int,int>>>l;                //nbr,edgeWt
    unordered_map<int,int> rp;
    
    //shortestPath Matrix
    vector<vector<int>> wt;
public:
    Graph(){V = 0;}
    
    void addEdge(int a, int b, int weight){
        int numNodes = int(l.size());
        //edgeCases
        if(a < 0 || b < 0){
            line();
            cout << "Negative key of nodes not allowed\n";
            line();
            return;
        }
        if(a < numNodes && b > numNodes){
            line();
            cout << "Key of node entered will cause memory leakage\n";
            cout << "Use '" << numNodes << "' for Key of nodeB\n";
            line();
            return;
        }
        if(a > numNodes && b < numNodes){
            line();
            cout << "Key of node entered will cause memory leakage\n";
            cout << "Use '" << numNodes << "' for Key of nodeA\n";
            line();
            return;
        }
        if(a > (numNodes-1) && b > (numNodes-1)){
            if(numNodes > 0){
                line();
                cout << "Key of nodes entered do not connect to existing Graph\n";
                cout << "Nodes present in current graph have key in range [0, " << numNodes-1 << "]\n";
                line();
                return;
            }
            else if(a != 0 && b != 1){
                line();
                cout << "Graph currently empty\n Use 0 and 1 for key of NodeA and NodeB respectively\n";
                line();
                return;
            }
            
        }
        //
        if(numNodes == 0){
            if(a == 0 && b == 1){
                rp[a] = rp[b] = 0;
            }
        }
        else if(a == numNodes){
            rp[a] = 0;
        }
        else if(b == numNodes){
            rp[b] = 0;
        }
        l[a].push_back(make_pair(b,weight));
        l[b].push_back(make_pair(a,weight));
    }
    void addResearchPotential(int a,int b){
        int numNodes = int(l.size());
        if(numNodes == 0){
            line();
            cout << "Graph Underflow Encountered\n";
            line();
        }
        if(a >= numNodes){
            line();
            cout << "Key of node entered not present in graph\nAdd Edges first if entering new Node\n";
            cout << "Nodes present in current graph have key in range [0, " << numNodes-1 << "]\n";
            line();
            return;
            
        }
        rp[a] = b;
    }
    
    void floydWarshallAlgo(int V){
        for(int k = 0; k < V; k++){
            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    if(wt[i][j] > wt[i][k] + wt[k][j]){
                        wt[i][j] = wt[i][k] + wt[k][j];
                    }
                }
            }
        }
    }
    
    //for executing Floyd Warshall's algorithm on existing vertices
    void updateMap(){
        int oldV = V;
        //resizing weightArray and putting MAX in new wts created
        V = int(l.size());
        if(V == 0){
            line();
            cout << "Graph Underflow encountered\n";
            line();
            return;
        }
        wt.resize(V);
        for(int i = 0; i < V; i++){
            wt[i].resize(V, MAX);
        }
        for(int i = oldV; i < V; i++){
            for(auto j = wt[i].begin(); j < wt[i].end(); j++){
                *j = MAX;
            }
        }
        //
        
        //updatingWeights
        for(auto p:l){
            int node = p.first;
            for(pair<int,int> nbr:l[node]){
                wt[node][nbr.first] = nbr.second;
                wt[nbr.first][node] = nbr.second;
            }
            
        }
        
        floydWarshallAlgo(V);
    }
    
    int traverse(int pos, int time, int b, vector<bool> visited, pair<int,pair<int,list<int>>> *optPaths){
        
        if(time < 0){
            return -2;
        }
        /*
        if(optPaths[pos].first != -2){
            return optPaths[pos].first;
        }
        */
        
        //Destination 'b' reached
        if(pos == b){
            
            optPaths[b].second.first = time;
            optPaths[b].second.second.clear();
            optPaths[b].second.second.push_front(b);
            optPaths[b].first = rp[b];
            return optPaths[b].first;
        
        }
        
        
        //mask will be for only current path nodes
        
        
        int maxRes = -1, dummy, maxST = -1;      //resCompare  //maxSpareTime
        for(auto nbr:l[pos]){
            
            int toVisit = nbr.first;
            int edge = nbr.second;
            
            if(visited[pos] == 0){
                visited[pos] = 1;
                dummy = traverse(toVisit, time-edge, b, visited, optPaths);
                visited[pos] = 0;
                
                //if res equal , check for spareTime
                if(dummy > maxRes || (dummy == maxRes && (maxST < optPaths[toVisit].second.first))){
                    //changing current best state
                    maxRes = dummy;
                    maxST = optPaths[toVisit].second.first;
                    
                    //modifiying optimalPath for current position
                    optPaths[pos] = optPaths[toVisit];
                    optPaths[pos].second.second.push_front(pos);          //adding pos to optPath
                    optPaths[pos].first += rp[pos];         //updating research
                    
                }
            }
            
        }
        
        if(maxRes == -1){
            return -2;
        }
        
        //returning research
        return optPaths[pos].first;
     
    }
    
    void printOptimalPath(pair<int,pair<int,list<int>>> p, int time, int a, int b){
        if(p.first == -2){
            line();
            cout << "No path possible from Node_" << a << " to Node_" << b << " within " << time << "hrs\n\n";
            line();
            return;
        }
        list<int> path = p.second.second;
        line();
        printf("Optimal Path from Node%d to Node%d within %dhrs:\n",path.front(),path.back(),time);
        cout << "Research Done = " << p.first << "units\n";
        cout << "Time taken = " << time - p.second.first << "hrs\nPath: ";
        while(!path.empty()){
            cout << path.front();
            path.pop_front();
            if(!path.empty()){
                cout << ",";
            }
        }
        cout << "\n";
        line();
        
    }
    
    void findPath(int a, int b, int time){
        int numNodes = int(l.size());
        if(numNodes == 0){
            line();
            cout << "Graph Underflow Encountered\n";
            line();
            return;
        }
        if(a >= numNodes && b >= numNodes){
            line();
            cout << "Entered Node key not present in graph\nCurrent graph has node keys in range [0," << numNodes-1 << "]\n";
            line();
            return;
        }
        if(time > 500){
            line();
            cout << "Excess time Constraint encountered\nUse value less than 500\n";
            line();
        }
        if(a == b){
            line();
            cout << "No movement required\n";
            line();
        }
        if(a < V && b < V && wt[a][b] > time){
            line();
            cout << "No path possible from Node_" << a << " to Node_" << b << " within " << time << "hrs\n";
            if(wt[a][b] < 10000){
            cout << "Min time to travel from Node" << a << "to Node" << b << " = " << wt[a][b] << "hrs( according to last mapUpdate)\n";
            }
            line();
            return;
        }
        
        list<int> path;
        int V0 = int(l.size());
        //research  //spareTime //path from pos to b
        pair<int,pair<int,list<int>>> *optPaths = new pair<int,pair<int,list<int>>>[V0];
        
        //initial research , spare times initialized to -2 for all nodes
        for(int i = 0; i < V0; i++){
            optPaths[i].first = -2;
            optPaths[i].second.first = -2;
        }
        //
        
        path.push_back(a);
        vector<bool> visited(l.size(),0);
        int totalResearch;
        totalResearch = traverse(a,time,b,visited,optPaths);
        
        printOptimalPath(optPaths[a],time,a,b);
    }
   
    
    
};

int main(){
    
    //ModelTest
    
    line();

    
    //graphEntry (mapInfo)
    Graph g;
    
    int flag,n1,n2,wt,rp,tc;
    
    
    for(;;){
        cout << "Enter operation to perform\n1.AddEdge\t2.AddResearchPotential\t3.FindPath\t4.UpdateMap\t0.EXIT\n";
        cin >> flag;
        if(flag == 0){
            exit(0);
        }
        
        switch(flag){
            case 1:
                cout << "Enter key of NodeA, NodeB and weight of edge b/w them\n";
                cin >> n1 >> n2 >> wt;
                g.addEdge(n1,n2,wt);
                break;
            case 2:
                cout << "Enter key of node and researchPotential\n";
                cin >> n1 >> rp;
                g.addResearchPotential(n1, rp);
                break;
            case 3:
                cout << "Enter key of initial, final node and timeConstraint\n";
                cin >> n1 >> n2 >> tc;
                g.findPath(n1,n2,tc);
                break;
            case 4:
                g.updateMap();
            default:
                break;
        }
        
        
        
    }
   
    return 0;
    
    
}


