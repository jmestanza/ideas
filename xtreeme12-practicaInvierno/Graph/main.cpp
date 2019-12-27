#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int numVertices;
    vector<int> *adjLists;
    Graph(int V);
    Graph(){

    }
    void addEdge(int src, int dest){

    }
};

void visit(int izq,int der){
    
}

int main() {
    int n;
    int m;
    bool u;
    bool v;
    cin >> n;
    cin >> m;

    Graph root;
    vector <pair<int, int>> edges;
    for(int i = 1 ; i<n ;i++) {
        cin >> u;
        if(i==1){
            root.numVertices=u;
        }
        cin >> v;
        edges.push_back(pair<int,int>(u,v));
        pair <int,int>pos = pair<int,int>(u,v);
        root.addEdge(pos.first,pos.second);
    }

    return 0;
}


