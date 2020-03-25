#include <bits/stdc++.h>

using namespace std;

class BinTree{
public:
    BinTree(BinTree * left_ ,BinTree* right_, int value_){
        this->left = left_;
        this->right = right_;
        this->value = value_;
    }
    BinTree(int value_){
        this->left = nullptr;
        this->right = nullptr;
        this->value = value_;
    }
    int value;
    BinTree * left;
    BinTree * right;
};


vector<BinTree*> aux;


void insertvalue(BinTree* root_rec, BinTree* node_to_insert,int level){
    if (node_to_insert->value <= root_rec->value){
        if(root_rec->left != nullptr){
            insertvalue(root_rec->left, node_to_insert, level+1);
        }else{
            root_rec->left = node_to_insert;
            cout << level << " ";
        }
        return;
    }else{
        if(root_rec->right != nullptr){
            insertvalue(root_rec->right, node_to_insert, level+1);
        }else{
            root_rec->right = node_to_insert;
            cout << level << " ";
        }
    }
}


int main() {
    int n;
    int aux;

    cin >> n;

    vector<BinTree*> nodes;
    for(int i= 0 ; i< n; i++){
        cin>>aux;
        nodes.push_back(new BinTree(aux));
    }


    BinTree* root = nodes[0];
    int level = 1;
    cout << level << " ";

    for(int i = 1; i< nodes.size(); i++){
        insertvalue(root,nodes[i],level+1);
    }

    while(root != nullptr){
        if (node_to_insert->value <= root_rec->value){
            if(root_rec->left != nullptr){
                insertvalue(root_rec->left, node_to_insert, level+1);
            }else{
                root_rec->left = node_to_insert;
                cout << level << " ";
            }
            return;
        }else{
            if(root_rec->right != nullptr){
                insertvalue(root_rec->right, node_to_insert, level+1);
            }else{
                root_rec->right = node_to_insert;
                cout << level << " ";
            }
        }
    }

    return 0;
}