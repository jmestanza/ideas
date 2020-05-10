#include <bits/stdc++.h>
#include <vector>
using namespace std;
int arr[101];

int main() {


    vector <int>no_null_places;

    int people;
    int n;
    int aux;
    cin >> people;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> aux;
        arr[aux]++;
    }

    for(int i = 0; i<100 ; i++){
        if(arr[i]>0){
            no_null_places.push_back(i);
        }
    }
    int ans=0;
    bool can_eat =true;
    int count=0;

    for(int j=1; j <= people && can_eat ; j++ ){
        for(int k=0;k<no_null_places.size();k++){
            arr[no_null_places[k]]--;
            if(arr[no_null_places[k]]>0){
                count++;
            }
        }
        if(count<people-j){
            can_eat=false;
        }else{
            count = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}