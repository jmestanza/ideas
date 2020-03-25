#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int index_ans = -1 ;
vector<ll> x;

#define MAX_ITS 55
#define MAX_B 28

ll arr_2d[MAX_B][MAX_ITS];


ll binSearch(int ind_a,int ind_b, int num , int b){
    if(ind_b > ind_a){
        int mitad = ind_a + (ind_b - ind_a) / 2;
        if (ind_a == ind_b-1){
            index_ans= ind_a; // devolvemos el mas chico
            return index_ans;
        }
        if( num >= arr_2d[b][mitad]){
            binSearch(mitad,ind_b,num, b);
        }else{
            binSearch(ind_a,mitad,num, b);
        }
    }else{
        cout << "inda supero a b" << endl;
    }
}

vector<int> overflow_vec;
int main() {

    ll new_value;
    vector<int> index;
    for(ll b = 2; b< MAX_B ; b++){
        bool overflow=false;
        for(ll n= 1; n< MAX_ITS; n++) {
            new_value = arr_2d[b][n-1] + n * pow(b,n);
            arr_2d[b][n] = new_value;
            if(new_value >= pow(10,18)+100 || new_value <0){
                if(overflow == false){
                    overflow_vec.push_back(n);
                    overflow= true;
                }
            }
        }
    }

    int busqueda = 24;
    int b2search = 26;
    int ans;
    //ans = binSearch( 0, MAX_ITS, busqueda ,b2search);
    //cout << ans << endl;

    cout << "[";
    for(int i = 0; i<overflow_vec.size(); i++){
        if(i == overflow_vec.size()-1){
            cout << overflow_vec[i]  ;
        }else{
            cout << overflow_vec[i] << "," << endl;
        }
    }

    cout << "]";
    cout << endl;
    cout << overflow_vec.size() << endl;
    return 0;

    // b = 26
    // num = 24
    // n que deberia dar es 0
}