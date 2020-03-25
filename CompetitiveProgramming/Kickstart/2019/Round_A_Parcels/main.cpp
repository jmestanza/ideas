#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii*> vii;
typedef vector<vector<int>> vvi;

int t, r, c, dist, act_max, i_,j_,min_time;

vii offices;
vvi matrix;
unordered_map<int, vii*>max_values;
string s;
vi aux_vec, answer;

void store_input(){
    for(int j = 0 ; j < r ; j ++){
        cin >> s; //  string with  "0"s or "1"s // 0 delivery aus, 1 delivery available
        for(int k = 0; k < c;k ++) {
            if (s[k] == '1') offices.push_back(new pair<int, int>(j, k));
        }
        matrix.push_back(vector<int>(c,INT_MAX)); // vector de 0's length: c
    }
}
void fill_dist_matrix(){
    for(int h = 0 ; h<offices.size() ; h++){
        for(int j = 0 ; j < r ; j++){
            for(int k = 0; k < c;k ++) {
                dist = abs(offices[h]->first-j) + abs(offices[h]->second-k);
                if(matrix[j][k]>dist){
                    matrix[j][k] = dist;
                }
            }
        }
    }
}

void get_max_values_coords(){
    act_max = INT_MIN;
    for(int j = 0 ; j < r ; j++){
        for(int k = 0; k < c;k ++) {
            if(matrix[j][k]>act_max){
                act_max = matrix[j][k];
                if(max_values.find(act_max) == max_values.end()){
                    max_values[act_max] = new vector<pii*>(1,new pii(j,k));
                }else{
                    max_values[act_max]->push_back(new pii(j,k));
                }
            }
        }
    }
}


int main(){
    cin >> t;
    for(int i = 0; i<t ; i++){
        cin >> r >> c; // r = rows , c = cols
        store_input();
        // fill matrix with distances to the offices
        fill_dist_matrix();
        get_max_values_coords();

        min_time = INT_MAX;
        for(int h= 0 ; h< max_values[act_max]->size() ; h++){
            i_ = (*max_values[act_max])[h]->first; // 1era pos de los mas maximos
            j_ = (*max_values[act_max])[h]->second; //  2da pos de los mas maximos
            // ahora trato de poner un local en los maximos y me quedo con el que me de menor tiempo de espera!
            for(int g =0 ; g < offices.size() ; g ++){
                dist = (abs(i_-offices[g]->first) + abs(offices[g]->second-j_))/2;
                if(dist < min_time){
                    min_time = dist;
                }
            }
        }
//        answer.push_back(min_time);
        cout << "Case #" << i+1 << ": " << min_time << endl ;
        offices.clear();
        aux_vec.clear();
        matrix.clear();
        max_values.clear();
    }
//    for(int i = 0 ; i<answer.size() ; i++){
//        cout << "Case #" << i+1 << ": " << answer[i] ;
//        if(i != answer.size()-1){
//            cout << endl;
//        }
//    }
    return 0;
}