#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,t,x,i;
    cin >> t;
    while(t--){
        cin >> x;   
        // x <= a.b + 1
        for(i = x-1 ; i < 1000000000 ; i++){
            if((x-1)%i == 0){
                b = (x-1) / i;
                break;
            }
        }
        cout << i << " " << b << endl;
    }
}