#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii*> vii;
typedef vector<vector<int>> vvi;
typedef unordered_map<char, int> mci;

string str;
int t, n, q, a, b, cnt_palindromo, odd_cnt,freq,low, high_val;
vi ans;
vector<char> letras;
vector<vector<int>> mat;


void get_unique_letras(){
    for(int z=0 ; z<str.size() ; z++) letras.push_back(str[z]);
    sort( letras.begin(), letras.end() );
    letras.erase( unique( letras.begin(), letras.end() ), letras.end());
}
void build_mat(void){
    int aux = 0;
    for(int k = 0 ; k < 27; k ++) mat.push_back(vector<int>(n,0));
    for(int k = 0 ; k < n ; k++) mat[int(str[k] -'A')][k] = 1;
    for(int k = 0 ; k < 27 ; k++){
        aux = 0;
        for(int l = 0 ; l< n ; l++){
            if(mat[k][l]==1){aux++;}
            mat[k][l] = aux;
        }
    }

}

int main(){
    cin >> t; // t hasta 100
    for(int i = 0; i<t ; i++) {
        cin>> n >> q;
        cin >> str;
        cnt_palindromo = 0;
        get_unique_letras();
        build_mat();

        for(int j = 0 ; j < q; j++){ // n y q  pueden ser 1e5
            odd_cnt = 0;
            cin >> a >> b;
            for(auto it = letras.begin(); it != letras.end(); ++it){
                if(a <= 1){
                    low = 0;
                }else{
                    low = mat[int((*it)-'A')][(a-1)-1];
                }
                high_val = mat[int((*it)-'A') ][b-1];
                freq = high_val - low;
                if(freq % 2 == 1) odd_cnt++;
            }
            if( odd_cnt == 1 || odd_cnt == 0) cnt_palindromo++;
        }
        letras.clear();
        mat.clear();
        ans.push_back(cnt_palindromo);
    }

    for(int i = 0 ; i<ans.size() ; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }
    return 0;
}