#include <iostream>

#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t, n, a, b, half;
    string ans;
    cin>>t;
    for(long long int i = 0; i<t ; i++){
        cin >> a >>b >> n;
        for(long long int j = 0 ; j<n ; j++){
            half = a + (b - a) / 2;
            cout << half << endl;
            cin >> ans;
            if(ans == "CORRECT") break;
            if(ans == "TOO_SMALL") a = half+1;
            else b = half-1;
        }
    }
}