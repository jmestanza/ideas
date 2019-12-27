#include <bits/stdc++.h>
using namespace std;

struct tree_info{
    int xi;
    int hi;
    tree_info(int _xi,int _hi){
        xi=_xi;
        hi=_hi;
    }
};
    const int maxn = 1e5+1;
    int DP[maxn][2];



int main() {

    int n;
    int xi,hi;

    vector<tree_info> trees;
    trees.push_back(tree_info(0,0));

    cin >> n;

    for(int i = 1; i<=n ; i++){
        cin>>xi>>hi;
        trees.push_back(tree_info(xi,hi));
    }
    for(int i=0 ; i<maxn ;i++){
        for(int j=0; j<2 ; j++){
            DP[i][j]=INT_MIN;
        }
    }

    //casos base
    DP[1][0]=1;
    DP[1][1]=INT_MIN;

    for(int i =2 ; i<=n ; i++){
            int caso1=INT_MIN;
            int caso2=INT_MIN;
            if(trees[i].xi-trees[i].hi > trees[i-1].xi){
                caso1=DP[i-1][0]+1;
            }else{
                caso1=DP[i-1][0];
            }
            if(trees[i].xi-trees[i].hi > trees[i-1].xi + trees[i-1].hi){
             caso2=DP[i-1][1]+1;

            }else{ // si hay un bug es aca
             caso2=DP[i-1][1]; //el otro escenario se compara
            }

            DP[i][0]=max(caso1,caso2);


            if(i==n){
                DP[i][1] = max(DP[i-1][1] +1,DP[i-1][0] +1);
            }else{
                if(trees[i+1].xi > trees[i].xi+trees[i].hi) { // si hay bug es aca
                    DP[i][1] = max(DP[i-1][1] +1,DP[i-1][0] +1);
                }else{
                    DP[i][1]=INT_MIN;
                }
            }

    }

    cout << ((n==1)? 1: DP[n][1]) << endl;

    return 0;
}