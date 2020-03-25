#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii*> vii;
typedef vector<vector<int>> vvi;
typedef unordered_map<char, int> mci;

string str;
int t, n, b, aux,total_weight;
bool found;
vi ans;
vector<char> letras;
vector<vector<int>> mat;
vi house_weigth;

int main(){
    cin >> t; // t hasta 100
    for(int i = 0; i<t ; i++) {
        cin>> n >> b;
        for(int j=0 ; j<n; j++){
            cin >> aux;
            house_weigth.push_back(aux);
        }
        aux = 0; // contador de casas
        total_weight=0;
        found = false;
        sort(house_weigth.begin(),house_weigth.end());

        for(int j =0 ; j< house_weigth.size() && !found ; j++){
            if(total_weight+house_weigth[j]<=b){
                total_weight += house_weigth[j];
                aux++;
            }else{
                found = true;
            }
        }
        house_weigth.clear();
        ans.push_back(aux);
    }
    for(int i = 0 ; i<ans.size() ; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }
    return 0;
}