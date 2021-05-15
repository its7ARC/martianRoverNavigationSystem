//Implementation of A* alogrithm
//(using diagonal distance heuristics)

//inclusions
#include <bits/stdc++.h>

//macros
#define ll int  //
#define pb push_back
#define pf push_front
#define ppf pop_front
#define ppb pop_back
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define vvi vector<vector<ll>>
#define res reserve
#define mii map<ll,ll>
#define umii unordered_map<ll,ll>
#define u_map unordered_map
#define s_bits __builtin_popcount    //
#define t_z __builtin_ctz   //
#define l_z __builtin_clz   //
#define lb lower_bound
#define ub upper_bound
#define inf INT_MAX
#define MOD 1000000007
#define fr(i,a,b) for(auto i = a; i < b; i++)
#define tr(it,a,b) for(auto (it) = (a); (it) != (b);)
using namespace std;

//input2DArray
template<class T = ll>
vector<vector<T>> in(ll r, ll c, ll key){
    vector<vector<T>> v(r+key, vector<T>(c+key));
    for(ll i = key; i < r+key; i++){
        for(ll j = key; j < c+key; j++){
            cin >> v[i][j];
        }
    }
    return v;
}

//inputArray
template<class T = ll>
vector<T> in(ll n, ll key){
    vector<T> a(n + key);
    for(ll i = key; i < n+key; i++){
        cin >> a[i];
    }
    return a;
}

/*####*/


//Program

void line(){
    fr(i,0,40) cout << "--";
    cout << "\n";
}

struct Cell{
    
    //parent i, j;
    ii par;
    
    //current cell details
    ii loc;
    ll f, g, h;
    Cell(ll g = INT_MAX, ll h = INT_MAX, ii curr = {-1,-1},ii par = {-1,-1}){
        loc = curr;
        this->par = par;
        this->g = g; this->h = h;
        f = (g==INT_MAX?g:g+h);
    }
};

struct Comp{
    bool operator()(const Cell &a, const Cell &b){
        return a.f > b.f;
    }
};

class A_Star{
    ll r, c;
    ii src, dest;
    vvi grid;
    vector<vector<Cell>> cell; //
    vvi close;
    priority_queue<Cell, vector<Cell>, Comp> open;
    
    
    //private functions
    
    bool integrity(ll i, ll j){ return (i>=0 && i<r) && (j>=0 && j<c);}
    bool is_valid(ll i, ll j){ return (i>=0 && i<r) && (j>=0 && j<c) && grid[i][j] != 1 && close[i][j] != 1;}
    bool is_dest(ii loc){ return (loc == dest);}
    
    //manhatten distance for h
    ll calculate_h(ii start, ii end){ return max(abs(start.ss-end.ss), abs(start.ff-end.ff));}
    
    bool find_path(){
        Cell q = cell[src.ff][src.ss] = Cell(0,0,{src.ff,src.ss});
        open.push(q);
        
        while(!open.empty()){

            q = open.top();
        
            // i+1,j
            if(is_valid(q.loc.ff+1,q.loc.ss)){
                ii nbr = {q.loc.ff+1,q.loc.ss};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i-1,j
            if(is_valid(q.loc.ff-1,q.loc.ss)){
                ii nbr = {q.loc.ff-1,q.loc.ss};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i,j+1
            if(is_valid(q.loc.ff,q.loc.ss+1)){
                ii nbr = {q.loc.ff,q.loc.ss+1};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i,j-1
            if(is_valid(q.loc.ff,q.loc.ss-1)){
                ii nbr = {q.loc.ff,q.loc.ss-1};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i+1,j+1
            if(is_valid(q.loc.ff+1,q.loc.ss+1)){
                ii nbr = {q.loc.ff+1,q.loc.ss+1};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i+1,j-1
            if(is_valid(q.loc.ff+1,q.loc.ss-1)){
                ii nbr = {q.loc.ff+1,q.loc.ss-1};

                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i-1,j+1
            if(is_valid(q.loc.ff-1,q.loc.ss+1)){
                ii nbr = {q.loc.ff-1,q.loc.ss+1};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
            
            // i-1,j-1
            if(is_valid(q.loc.ff-1,q.loc.ss-1)){
                ii nbr = {q.loc.ff-1,q.loc.ss-1};
                
                ll g = q.g+1;
                ll h = calculate_h(nbr,dest);
                ll f = g+h;
                if(cell[nbr.ff][nbr.ss].f > f){
                    cell[nbr.ff][nbr.ss] = Cell(g,h,nbr,{q.loc.ff,q.loc.ss});
                    open.push(cell[nbr.ff][nbr.ss]);
                }
                //destination reached
                if(is_dest(nbr)){ return 1;}
            }
           
            close[q.loc.ff][q.loc.ss] = 1;
            open.pop();
        }
        return 0;
    }
    
    void print_path(){
        vvi ans = grid;
        Cell curr = cell[dest.ff][dest.ss];
        while(1){
            ans[curr.loc.ff][curr.loc.ss] = 9;
            if(curr.par.ff == -1) break;
            curr = cell[curr.par.ff][curr.par.ss];
        }
        line();
        line();
        cout << "Output Grid\n";
        line();
        cout << "Path vertices -> '9'\n";
        line();
        fr(i,0,r){
            fr(j,0,c) cout << ans[i][j] << " ";
            cout << "\n";
        }
        line();
        line();
        return;
    }
    
public:
    
    void input_grid(){
        cout << "Enter number of rows and columns in grid respectively\n";
        cin >> r >> c;
        cell = vector<vector<Cell>>(r,vector<Cell>(c));
        close = vvi(r,vi(c));
        
        cout << "Enter the matrix with '1' representing obstacles and '0' representing traversable points\n";
        grid = in(r,c,0);
    }
    
    void navigate(){
        if(grid.empty()){
            cout << "Map underflow encountered\n";
            return;
        }
        
        //Src, destination vertex input
        ll x,y;
        cout << "Enter co-ordinates of source vertex\n";
        cin >> x >> y;
        if(!integrity(x,y)){ cout << "Invalid source encountered\n"; return;}
        src = {x,y};
        
        cout << "Enter co-ordinates of destination vertex\n";
        cin >> x >> y;
        if(!integrity(x,y)){ cout << "Invalid destination encountered\n"; return;}
        dest = {x,y};

        cout << dest.ff << " " << dest.ss << "\n";
    
        //Printing found path
        if(!find_path()){
            line();
            cout << "No traversable path from src to destination\n";
            line();
            return;
        }
        else print_path();
    }
    
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << "Implementation of A Star Algorithm for NavMars\n";
    line();
    A_Star a_star;
    a_star.input_grid();
    a_star.navigate();
    
    return 0;
}

/*
 Sample iNput
 9 10
 0 1 0 0 0 0 1 0 0 0
 0 0 0 1 0 0 0 1 0 0
 0 0 0 1 0 0 1 0 1 0
 1 1 0 1 0 1 1 1 1 0
 0 0 0 1 0 0 0 1 0 1
 0 1 0 0 0 0 1 0 1 1
 0 1 1 1 1 0 1 1 1 0
 0 1 0 0 0 0 1 0 0 0
 0 0 0 1 1 1 0 1 1 0
 */

