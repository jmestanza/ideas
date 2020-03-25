#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int T, N, K, P, suma_stack_actual;
vi ans;
vi aux_vec;
#define EPS 10
#define MAXN 50
#define MAXK 30
int all_stacks[MAXN+EPS][MAXK+EPS];
int dp[MAXN+EPS][MAXN*MAXK+EPS]; // maximos buckets(N), maximas decisiones(N*K)
int main(){
    cin >> T; // t hasta 100
    for(int t = 0; t<T ; t++) {
        cin>> N >> K >> P;
        for(int j=0 ; j<N; j++){
            for(int l= 0 ; l<K; l++){
                cin >> all_stacks[j][l];
            }
        }
        for(int i = 0 ; i<= P ; i++){
            dp[0][i] = 0 ; // stack 0 no elegimos platos
        }
        for(int i = 1 ; i<= N ; i++){
            // stack j esimo
            for(int p = 0; p<= P ; p++){
                // decision plato p esimo
                dp[i][p] = 0;
                suma_stack_actual = 0;
                // vamos a observar en relacion a las decisiones tomadas en stacks
                // previos y el actual
                for(int q = 0 ; q<= K ; q ++){ // si o si pongo el plato q del stack
                    // hago todos los casos!
                    if(p-q>=0)
                        // el p - q es por lo siguiente:
                        // si puse q en el anterior stack, puedo poner p-q ahora
                        // max-> lo agrego o no hago nada, el que maximize beauty
                        // d[i][p] tiene sentido ya que lo voy a recorrer varias
                        // veces (aca brilla overlapping subproblems)
                        // es decir, si recorriera NxP, pasaria una vez por dp[i][p]
                        // pero al anadir q, se puede volver a recorrer el lugar que pase
                        dp[i][p]=max(dp[i-1][p-q] + suma_stack_actual, dp[i][p]);
                    // suma va incrementando abajo
                    // a medida que agrego el plato q esimo del stack anterior
                    if(q<K)
                        suma_stack_actual += all_stacks[i-1][q];
                    // sumo el valor el plato q esimo del stack anterior
                }
            }
        }
        for(int j = 0 ; j <= N; j++ ){
            aux_vec.push_back(dp[j][P]);
        }
        sort(aux_vec.begin(),aux_vec.end(),greater<int>());
        ans.push_back(aux_vec[0]);
        aux_vec.clear();
    }
    for(int i = 0 ; i<ans.size() ; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }
    return 0;
}