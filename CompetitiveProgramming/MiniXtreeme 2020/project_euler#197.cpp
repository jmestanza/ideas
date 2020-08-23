#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


double f(double b,double x){
    return floor(pow(2,b-pow(x,2)))*pow(10,-9);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    double ans,b,last,u0;
    cin >> u0 >> b;
    ans = u0;
        
    for(int i = 0 ; i<100000 ;  i++){
        last = ans;
        ans = f(b,ans);
    }
    cout.precision(11);
    cout << last+ans << endl;

    return 0;
}
