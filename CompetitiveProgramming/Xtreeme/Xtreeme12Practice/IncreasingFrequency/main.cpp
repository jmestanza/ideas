#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN int(5e5+20)

vector<int> freqs[MAXN];
vector<int> A;

int max_subarray(vector<int> A){
    int max_so_far;
    int max_ending_here = max_so_far = A[0];

    for(int i =1 ; i< A.size() ; i++){
        int x = A[i];
        max_ending_here = max(x, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void printVec(vector<int>& A){
    cout << endl;
    for(int i = 0 ; i < A.size() ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


vector<int> genCompressed(int c,int d, int n){
    vector<int> ans;
    for(int i =0 ; i < freqs[c].size() ; i++){

    }
    for(int i =0 ; i < freqs[d].size() ; i++){

    }
}

int main(){
    int n , c, aux;
    cin >> n >> c;
    for(int i = 0 ; i < n ; i++){
        cin >> aux;
        freqs[aux].push_back(i);
        A.push_back(aux);
    }

    return 0;
}

