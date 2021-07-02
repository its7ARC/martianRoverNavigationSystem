//
//  main.cpp
//  NavMars
//
//  Created by Anshuman Raj Chauhan.
//

#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

void line(){
    for(int i = 0;i < 40 ; i++) cout << "--";
    cout << "\n";
}

struct Vertex{
    int x; //x-coordinate
    int rp; //research potential
    Vertex(int x, int rp):x(x),rp(rp){}
};

class Model{
    //number of vertices in graph, maximum allowed vertices, maximum allowed time_budget.
    int cnt_v, mx_v, mx_tb;
    //vertex - {x_coordinate ,research potentials}.
    vector<Vertex> v;
    //weighted adjacency list - pairs: 'nbr_vertex_index - edge_wt'
    vector<list<pair<int,int>>> l;
    //dp for computing optimal path
    vector<vector<int>> dp;
    
public:
    Model():cnt_v(0), mx_v(1000), mx_tb(100), l(vector<list<pair<int,int>>>(mx_v)){}
    
    void addVertex(int x, int res_pot = 1);
    void addEdge(int v1, int v2, int edge_wt);
    int optimalPath(int curr, int dest, int time_budget);
    void findPath(int src, int dest, int time_budget);
    void printPath(int src, int dest, int time_budget);
};

void Model::addVertex(int x, int res_pot){
    if(cnt_v == mx_v){ cout << "Graph Overflow\n"; return;}
    cnt_v++; v.push_back({x,res_pot});
}

void Model::addEdge(int v1, int v2, int edge_wt){
    if(v1 < 0 || v2 < 0 || v1 >= cnt_v || v2 >= cnt_v){
        cout << "Input Vertices do not exist\n";
        cout << "Present Graph has vertices in range" << 0 << " - " << cnt_v-1 << "\n";
        return;
    }
    if(v[v1].x < v[v2].x){
        for(auto pr:l[v1]) if(pr.first == v2){ pr.second = edge_wt; return;}
        l[v1].push_back({v2,edge_wt}); return;
    }
    else if(v[v1].x > v[v2].x){
        for(auto pr:l[v2]) if(pr.first == v1){ pr.second = edge_wt; return;}
        l[v2].push_back({v1,edge_wt}); return;
    }
    else{ cout << "Edge cannot be added since both vertices have same x-coordinate\n"; return;}
}

int Model::optimalPath(int curr, int dest, int tb){
    if(tb < 0) return -1;
    if(dp[curr][tb] != -1) return dp[curr][tb];
    if(curr == dest) return dp[curr][tb] = v[dest].rp;
    
    for(auto pr:l[curr]){
        int nbr = pr.first, edge_wt = pr.second;
        int res_nbr = optimalPath(nbr,dest,tb-edge_wt);
        if(res_nbr != -1) dp[curr][tb] = max(dp[curr][tb],res_nbr + v[curr].rp);
    }
    return dp[curr][tb];
}

void Model::printPath(int curr, int dest, int tb){
    if(curr == dest){ cout << dest << "\n"; return;}
    cout << curr << " -> ";
    int nxt = -1, edg = INT_MAX, mx_res = -1;
    for(auto pr:l[curr]){
        int nbr = pr.first, edge_wt = pr.second;
        if(tb-edge_wt >= 0 && dp[nbr][tb-edge_wt] > mx_res){ nxt = nbr; mx_res = dp[nbr][tb-edge_wt]; edg = edge_wt;}
    }
    printPath(nxt, dest, tb-edg);
}

void Model::findPath(int src, int dest, int time_budget){
    
    line();
    cout << "Source Vertex = " << src << "\t" << "Destination Vertex = " << dest << "\n";
    cout << "Time Budget = " << time_budget << "\nOutput:\n";
    
    //Edge cases
    if(src < 0 || src >= cnt_v){ cout << "Invalid source Vertex\nPresent graph has vertices in range : 0 - " << cnt_v-1 << "\n"; line(); return;}
    if(dest < 0 || dest >= cnt_v){ cout << "Invalid source Vertex\nPresent graph has vertices in range : 0 - " << cnt_v-1 << "\n"; line(); return;}
    if(src == dest){ cout << "No movement reqired\n"; line(); return;}
    if(v[src].x >= v[dest].x){ cout << "No path found (Backward movement for rover not allowed)\n"; line(); return;}
    if(time_budget <= 0 || time_budget > mx_tb){ cout << "Invalid time budget\nTry in range [1 - 100]\n"; line(); return;}
    
    vector<vector<int>> temp(cnt_v,vector<int>(time_budget+1,-1)); dp = temp;
    optimalPath(src, dest, time_budget);
    if(dp[src][time_budget] == -1){ cout << "No path possible in given time budget\n"; line(); return;}
    cout << "Optimal Path is: \n";
    printPath(src, dest, time_budget);
    cout << "Total Research = " << dp[src][time_budget] << " units.\n";
    line();
    return;
}


int main(){
    
    //testing
    Model model;
    
    //Graph Construction
    model.addVertex(0,10);
    model.addVertex(1,15);
    model.addVertex(2,15);
    model.addVertex(3,5);
    model.addVertex(4,12);
    model.addVertex(5,20);
    model.addVertex(6,30);
    model.addVertex(7,100);
    model.addVertex(8,40);
    model.addVertex(9,7);
    model.addVertex(10,10);
    
    model.addEdge(0,1,4);
    model.addEdge(0,2,3);
    model.addEdge(0,3,2);
    model.addEdge(0,8,8);
    model.addEdge(1,4,7);
    model.addEdge(2,6,7);
    model.addEdge(3,9,2);
    model.addEdge(4,5,5);
    model.addEdge(5,6,5);
    model.addEdge(5,7,10);
    model.addEdge(6,7,4);
    model.addEdge(7,8,2);
    model.addEdge(7,9,1);
    model.addEdge(8,10,5);
    
    //finding paths
    
    //edgeCases
    model.findPath(0,15,5);
    model.findPath(10,0,15);
    model.findPath(-2,5,10);
    model.findPath(0,10,0);
    model.findPath(0,0,10);
    
    //
    model.findPath(0,10,5);
    model.findPath(0,10,15);
    model.findPath(0,10,25);

    return 0;
}
