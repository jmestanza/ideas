#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

map<ll,map<ll,ll>> graph; // ingreso con numero de nodo y me devuelve a donde puedo ir
vector<ll> costs;

bool mat[30][30];

map<int, map<int,bool>> visited;

ostream & operator << (ostream &out, const pii &c)
{
    out << c.first << " " << c.second;
    return out;
}

bool isInvalid(int r,int c,int rp,int cp){
    if(r == rp || c == cp || (r-c)==(rp-cp) || (r+c == rp+cp)){
        return true;
    }else{
        return false;
    }
}


bool can_jump(pii &pos,int R,int C){
    bool found = false;
    for(int i = 0 ; i < R && !found; i ++){
        for(int j = 0;  j < C && !found ; j++){
            if(!isInvalid(pos.first,pos.second,i,j)){
                if(mat[i][j] == 0){
                    pos.first  = i;
                    pos.second = j;
                    mat[i][j]=1;
                    found = true;
                }
            }
        }
    }
    return found;
}



int main(){
    ll T,R,C;
    vector<pair<string,vector<pii>>> ans;
    cin >> T;
    pii pos;
    bool found;
    vector<pii> way;

    while(T--){
        cin >> R >> C;
        // itero afuera de mi cuadrado buscando uno que cumpla la condicion
        found = false;
        for(int i =0; i < R && !found; i ++){
            for(int j =0; j < C && !found; j ++){
                way.clear();
                pos = make_pair(i,j);        
                way.push_back(mp(pos.first+1,pos.second+1));
                mat[pos.first][pos.second] = 1;
                int cnt_jumps = 1;
                for(int z = 0 ; z < R*C ; z++){
                    if(can_jump(pos,R,C)){
                        way.push_back(mp(pos.first+1,pos.second+1));
                        cnt_jumps++;
                    }
                }
                if(cnt_jumps == R*C) found = true;
                for(int k = 0 ; k < R ; k++){
                    for(int w = 0 ; w < C ; w++){
                        mat[k][w] = 0;
                    }
                }
            }    
        }
        if(found){
            ans.push_back(pair<string,vector<pii>>("POSSIBLE",way));
        } 
        else ans.push_back(pair<string,vector<pii>>("IMPOSSIBLE",vector<pii>()));
    }

    for(int i =0 ; i< ans.size() ; i++){
        cout << "Case #" << i+1 << ": ";
        if(ans[i].second.size() >0){
            cout << "POSSIBLE" << endl;
            for(int k = 0 ; k < ans[i].second.size(); k++){
                cout << ans[i].second[k] << endl;
            }
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
}