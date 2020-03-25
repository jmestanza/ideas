#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int base=16;
    vector <int> ans;
    cin >> N;
    int nivel=0;
    while(N/base != 0){
        nivel++;
        ans.push_back(N%base);
        N/=base;
    }
    ans.push_back(N%base);

    for( int i = ans.size()-1 ; i>=0 ; i--){
        cout << ans[i] << " " ;
    }


    return 0;
}