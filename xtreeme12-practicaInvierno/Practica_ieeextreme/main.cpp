#include <iostream>
#include <vector>
#include <tgmath.h>
using namespace std;

bool isPalindrome(int n){
    vector<int> digits;
    int aux = n;
    int dig;
    for(int i=5 ; i>=0 ; i--){
        dig= int(n/pow(10,i));
        digits.push_back(dig);
        aux = aux- pow(10,i)*dig;
    }
    bool isPal=true;
    for(int i =0 ; i<= 2  ; i ++){
        if(digits[i] != digits[5-i]){
            isPal= false;
        }
    }
    return isPal;
}

int main() {
    cout << isPalindrome(123321) << endl;
    return 0;
}