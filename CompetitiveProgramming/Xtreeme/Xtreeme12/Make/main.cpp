#include <iostream>
#include <vector>
using namespace std;
typedef long long unsigned llu;
int main() {
    llu n;
    llu Q;
    cin >> n;
    vector<llu>players;
    llu aux;
    for(llu i = 0 ; i<n ; i++){
        cin >> aux;
        players.push_back(aux);
    }
    cin >> Q;
    string possible;

    for(llu query = 0; query<Q ; query++){
        possible = "NO";
        llu actual;
        cin >> actual;
        for(llu j = 0; j < n ; j++){
            for(llu k = j; k < n ; k++){
                llu aux = players[j]&players[k];
                if(aux == actual)
                    possible = "YES";
            }
        }
        cout << possible <<endl;
    }
   return 0;
}