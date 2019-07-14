#include <iostream>
#include <vector>
#include <tgmath.h>
using namespace std;

class BTnode{
public:
    BTnode(char data_){
        right = nullptr;
        left = nullptr;
        data = data_;
    }
    BTnode(BTnode* left_,BTnode* right_,char data_){
        right = right_;
        left = left_;
        data = data_;
    }

    char data;
    BTnode* right;
    BTnode* left;
};

vector<BTnode*> bfs(BTnode * root){
    bool end =false;
    int nivel=0;
    vector<BTnode*> q;
    q.push_back(root);
    while(!end){
        int size_act =q.size();
        int atleastonenotnull=false;
        for(int i = pow(2,nivel)-1; i<size_act; i++){
            if(q[i]==nullptr){
                q.push_back(nullptr);
                q.push_back(nullptr);
            }else{
                if(q[i]->left != nullptr|| q[i]->right != nullptr){
                    atleastonenotnull=true;
                }
                q.push_back(q[i]->left);
                q.push_back(q[i]->right);
            }
        }
        if(atleastonenotnull==false){
            end=true;
        }
        nivel++;
    }
    return q;
}

void dfs(BTnode* root){
    if(root == nullptr){
        return;
    }else{
        //pre visit
        cout << root->data << " ";
        dfs(root->left);
        dfs(root->right);
        //post visit
    }
}

int main() {
    // Primero hago los hijos xDDDD
    BTnode B = BTnode('B');
    BTnode D = BTnode('D');
    BTnode F = BTnode('F');
    BTnode J = BTnode('J');
    BTnode K = BTnode('K');
    BTnode L = BTnode('L');

    //Primer arbol
    BTnode E = BTnode(&F,nullptr,'E');
    BTnode C = BTnode(&D,&E,'C');
    BTnode A = BTnode(&B,&C,'A');

    //segundo arbol

    BTnode H = BTnode(nullptr,&J,'H');
    BTnode I = BTnode(&K,&L,'I');
    BTnode G = BTnode(&H,&I,'G');
    //root
    BTnode R = BTnode(&A,&G,'R');


    vector<BTnode*> ans= bfs(&R);

    int level = 0;
    for(int i = 0; i< ans.size() ; i++) {
        if (ans[i] != nullptr){
            cout << ans[i]->data << " ";
        }
        if(i == pow(2,level)-1){
            cout << endl;
            level++;
        }
    }
    return 0;
}