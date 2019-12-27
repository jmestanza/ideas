#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

void process(long long int total,long long int src,long long int dst,long long int dist){
    long long int steps=0;
    if(abs(src-dst)%dist == 0){
        steps = abs(src-dst)/dist;
    }else if( abs(total-dst)%dist ==0){
        steps = abs(total-dst)/dist+abs(total-src)/dist+1;
    }else if( abs(dst-1)%dist == 0){
        steps =  abs(dst-1)/dist+abs(1-src)/dist+1;
    }else{
        steps = -1;
    }
    cout << steps << endl;
    return;
}


int main() {
    long long int testcases;
    long long int n,x,y,d;
    cin >> testcases;
    for(long long int i =0 ; i < testcases; i++){
        cin >> n >> x >> y >> d ;
        process(n,x,y,d);
    }
    return 0;
}