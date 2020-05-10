#include <bits/stdc++.h>
using namespace std;


get_most_significant_digit(int n, vector<int>& dig){
    bool found_1 = false;
    int digit;
    do {
        digit = n % 10;
        dig.push_back(digit);
        if(digit == 1 || digit == 0){
            found_1 = true;
        }
        n /= 10;
    } while (n > 0);
    return found_1;
}
unordered_map<int,int> memory;
void insert_in_memory(int aux){
        if(memory.find(aux) == memory.end()){
            memory[aux] = 1;
        }else{
            memory[aux]++;
        }
}

int main(){
    int t, n;
    vector<string> ans;
    vector<int> digit;
    string aux;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1){
            aux += "-1";
            ans.push_back(aux);
        }else{
            aux += "2";
            for(int i = 0 ; i < n - 1 ;  i ++) {
                aux+="3";
            }
            ans.push_back(aux);
        }
        aux.clear();
    }
    for(int j = 0 ; j < ans.size() ; j++){
        cout << ans[j] << endl;
    }
    // for(int i = 10; i< 1000000 ; i++){
    //     bool found_1 = get_most_significant_digit(i, digit);
    //     int aux = digit[0] + digit[1]*10; // me quedo con los dos primeros digitos
    //     if(i % 2 != 0 && i %3 != 0 && i %5 != 0 && i%7!=0 && !found_1){
    //         insert_in_memory(aux);
    //     }
    //     digit.clear();
    // }
    // for(auto it = memory.begin(); it != memory.end(); ++it){
    //     cout << "Numero "<< it->first << " Frecuencia " << it->second << endl;
    // }
// Numero 79 Frecuencia 1
// Numero 73 Frecuencia 1
// Numero 67 Frecuencia 1
// Numero 59 Frecuencia 1
// Numero 49 Frecuencia 1
// Numero 37 Frecuencia 1
// Numero 89 Frecuencia 2
// Numero 83 Frecuencia 2
// Numero 77 Frecuencia 2
// Numero 53 Frecuencia 2
// Numero 47 Frecuencia 2
// Numero 97 Frecuencia 1
// Numero 23 Frecuencia 2

}