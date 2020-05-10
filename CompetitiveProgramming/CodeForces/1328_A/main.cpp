#include <bits/stdc++.h>

using namespace std;
int main() {
    int a,b,T,T2,aux;
    int arr[10000];
    cin >> T;
    T2 = T;
    vector<int> ans;
    while(T--){
        cin >> a >> b;
        arr[T] = a%b==0? 0 :b<a? (b-(a%b)): b-a; // si es menor siempre es la resta
    }
    cout << endl;
    while(T2--){
        cout << arr[T2] << endl;
    }
    return 0;
}
