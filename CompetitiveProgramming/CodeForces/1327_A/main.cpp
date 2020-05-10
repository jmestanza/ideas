#include <bits/stdc++.h>
using namespace std;
typedef long long ll;  

int main() {
    ll n,k,T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        cout << ( (k%2 == n%2) && (k*k <= n) ? "YES" : "NO") << endl;
    }
    return 0;
}
