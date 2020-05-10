#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

map<ll,map<ll,ll>> graph; // ingreso con numero de nodo y me devuelve a donde puedo ir
vector<ll> costs;

struct RetrieveKey
{
    template <typename T>
    typename T::first_type operator()(T keyValuePair) const
    {
        return keyValuePair.first;
    }
};


#define FOR(i,n) for(ll (i)= 0 ; (i) < (n); (i)++)

ll arg_min(vector<ll> dist){
    return min_element( dist.begin(), dist.end())-dist.begin();
}
ll arg_max(vector<ll> dist){
    return max_element( dist.begin(), dist.end())-dist.begin();
}

vector<ll> get_adyacent_nodes(ll u){
    vector<ll> ady;
    transform(graph[u].begin(), graph[u].end(), back_inserter(ady), RetrieveKey());
    return ady;
}

ll arg_min_of_not_marked(vector<ll> dist, map<ll,bool> visited){
    ll min_idx = -1;
    ll min_val = INT_MAX;
    for(ll i =0  ; i < dist.size(); i++){
        if( (dist[i]< min_val) &&  (visited.find(i) == visited.end())  ){
            min_val = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

ll dijkstra(ll first,ll last, ll m){
    // Both directed and undirected graphs.
    // All edges must have nonnegative weights.
    // Graph must be connected.
    
    // asumo que es conexo;
    // chequear con dfs previamente;
    map<ll,bool> visited;
    vector<ll> dist = vector<ll>(last+1,INT_MAX);
    vector<ll> ady;
    ll u,v;
    u = first;
    dist[u] = 0;
    // si hay N nodos, last = N-1
    for(ll k = 0 ; k<m && u != last; k++){ // si llegue al ultimo o ya recorri todas las edges, paro
        u = arg_min_of_not_marked(dist,visited);
        ady = get_adyacent_nodes(u);
        for(ll i = 0 ; i < ady.size() ; i++){
            v= ady[i];
            if(visited.find(v) == visited.end()){// si no tome este camino ya,
                dist[v]= min(dist[u] + graph[u][v], dist[v]); // considero la posibilidad de tomarlo
            } 
        }
        visited[u] = 1; // ya procese este nodo
        ady.clear();
    }
    return dist[last];
}

map<ll,bool> marked;   

// ll dfs(ll u){
//     ll v;
//     marked[u] = true;
//     vector<ll> ady;
//     ady = get_adyacent_nodes(u);
//     for(int i = 0 ; i < ady.size() ; i++){
//         v = ady[i];
//         if(marked.find(v) == marked.end()){// si no tome este camino ya,
//             return 1+dfs(v);
//         }
//     }
//     return 1;
// }

// bool isConnected(ll n){ // si es conexo, con n nodos
//     int cont =dfs(0); // empiezo con cualquiera, por ej el 0
//     return cont == n? true:false;
// }

void traverse(ll u, bool visited[], ll n) {
   visited[u] = true; //mark v as visited
   for(ll v = 0; v<n; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            traverse(v, visited, n);
      }
   }
}
bool isConnected(ll n) {
   bool *vis = new bool[n];
   //for all vertex u as start point, check whether all nodes are visible or not
   for(ll u; u < n; u++) {
      for(ll i = 0; i<n; i++)
         vis[i] = false; //initialize as no node is visited
         traverse(u, vis, n);
      for(ll i = 0; i<n; i++) {
         if(!vis[i]) //if there is a node, not visited by traversal, graph is not connected
            return false;
      }
   }
   return true;
}


int main(){
    ll n, m, a, b, cost;
    cin >> m >> n;
    for(ll i = 0 ; i< m ; i++){
        cin >> a  >> b >> cost;
        b -= 1;
        a -= 1; 
        // viene [a][b] y tengo que guardar tambien la info de [b][a]
        graph[a][b] = cost;
        graph[b][a] = cost;
    }
    if(n != 1){
        if(isConnected(n)){
            cout << dijkstra(0,n-1, m) << endl;
        }else{
            cout << -1 << endl;
        }
    }else{
        cout << 0 << endl;
    }
}