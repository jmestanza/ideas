#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int cnt=0 ;
int maxlvl=0;
int maxpos = 0;
class node;

vector<node*> node_list;

class node{
public:
    char place;
    int shown;
    int lvl;
    char char_;
    node *left,*right;

    node(node* left_, node* right_,char  char_){
        left = left_;
        right = right_;
        this->char_ = char_;
        place = -1;
        shown = false;
    }

    void compute_count(int lvl = 0){

       node_list.push_back(this);
        this->lvl = lvl;

        if (this->left != 0){
            this->left->compute_count(lvl + 1);
        }
        this->place = cnt;
        cnt += 1;
        if (this->right != 0){
            this->right->compute_count(lvl + 1);
        }

        maxlvl = max(this->lvl , maxlvl);
        return;
    }
};



node* recu(string a , string b){
    if (b.size() == 0){
        return new node(nullptr ,nullptr ,' ');
    }
    char root = b[0];
    if (a.size() == 1){
        return new node(nullptr, nullptr, root);
    }


    int j = 0;
    for (int i = 0 ; i< a.size() ; i++){
        if (a[i] == root){
            break;
        }
        j += 1;
    }

    node* left_child = recu(a.substr(0,j), b.substr(1,j));
    node* right_child = recu(a.substr(j+1,a.size()-j-1), b.substr(j+1,a.size()-j-1));

    return new node(left_child ,right_child ,root);
}


int main() {
    string s1 , s2;
    while(cin >> s1  >> s2 ) {

        vector<node*> reset_list;

        node_list=reset_list;
        cnt = 0;
        maxlvl = 0;
        maxpos = 0;

        node *three = recu(s1, s2);


        vector<vector<node *>> levels;

        three->compute_count();

        for (int i = 0; i <= maxlvl; i++) {
            levels.push_back(vector<node *>());
        }
        for (int i = 0;i < node_list.size(); i++) {
            levels[node_list[i]->lvl].push_back(node_list[i]);
        }

        maxpos = node_list.size();
        for (int i = 0;i < levels.size();i++){

            vector <char> showlvl;
            for (int i = 0;i < maxpos;i++){
                showlvl.push_back(' ');
            }
            for (int j = 0;j < levels[i].size(); j++){
                node* nd = levels[i][j];
                showlvl[nd->place] = nd->char_;
            }

            for (int j=0; j< showlvl.size() ; j++)
                cout << showlvl[j];
            cout << endl;
        }
    }

    return 0;
}