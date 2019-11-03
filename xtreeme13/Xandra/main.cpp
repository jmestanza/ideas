#include <bits/stdc++.h>

using namespace std;

class Node {       // The class
public:             // Access specifier
    Node(int u_, int v_, int w_){
        this->u = u_;
        this->v = v_;
        this->w = w_;
    }
    int u;        // Attribute (int variable)
    int v;  // Attribute (string variable)
    int w;
    friend ostream& operator<<(ostream& os, const Node& Node_arg);
};


ostream& operator<<(ostream& os, const Node& Node_arg)
{
    os << Node_arg.u << ' ' << Node_arg.v << ' ' << Node_arg.w;
    return os;
}



int take_path(vector<Node> graph_tree,int number){
    Node * first_node =&graph_tree[number];
    Node * second_node =&graph_tree[number+1];

    int ans =  max(take_path(first_node), take_path(second_node));
    return ans;
}



int main() {
    int n;
    int last_u = INT32_MIN;
    int u=INT32_MIN;
    int v;
    int w;

    cin >> n;
    vector<Node> graph_tree;

    for(int i = 0 ; i < n-1 ; i++){
        cin >> u ;
        cin >> v ;
        cin >> w ;
        graph_tree.push_back(Node(u,v,w));
    }


    for(int i = 0 ; i < graph_tree.size() ; i++){
        cout<< graph_tree[i] << endl;
    }

    // desde el primero puedo ir a todos, es un binary tree!!
    // voy del primero a
    //take_path(graph_tree[0])


    return 0;
}