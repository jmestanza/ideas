#include <bits/stdc++.h>
using namespace std;

#define MAXN 499097567 // 500M approx, 5 * 10^8
#define SQMAXN 22340

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template <typename T> ll binSearch(ll a,ll b, T num2search, T (&arr)[]){
    // assumptions : the array is sorted
    //             : the num2search is in the array
    // example:
    //int numbers[] = {1,2,3,3,4};
    //ll index = binSearch <int> (0, sizeof(numbers)-1, 3, reinterpret_cast<int (&)[]>(numbers));
    if(b > a){
        int half_index = a + (b - a) / 2;
        if (a == b - 1){ // when its reduced to two contigous numbers, take the smallest (ind_a)
            return a;
        }
        if( num2search >= arr[half_index]){
            return binSearch(half_index,b,num2search,arr);
        }else{
            return binSearch(a,half_index,num2search, arr);
        }
    }
}


int main() {
    cout << "hello" << endl;
    return 0;
}
