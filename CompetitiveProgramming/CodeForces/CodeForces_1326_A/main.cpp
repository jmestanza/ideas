#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

std::ostream& operator<<(std::ostream& os, const std::vector<ll> &input)
{
    for (auto const& i: input) {
        os << i << " ";
    }
    return os;
}

vi digits;

void get_digits(ll number){
    ll digit;
    ll auxn = number;
    do {
        digit = auxn % 10;
        digits.push_back(digit);
        auxn /= 10;
    } while (auxn > 0);
}

int main(){
    ll t, n, auxn, start, number, end, failed_digit, is_good;
    bool found = false;
    cin >> t;
    for(ll i = 0; i<t ; i++){
        cin >> n;
        auxn = n-1; start = 1;
        for(ll j = 0; j < auxn ; j ++) start *= 10;
        end = start*10;

        found = false;

        for(ll j = start; j < end; j ++){
            get_digits(j);
            is_good = true;
            for(ll k =  0; k < digits.size() ; k++){
                //cout << digits << endl;
                failed_digit = (digits[k] == 0) || (digits[k] == 1) || (j % digits[k] == 0);
                if(failed_digit){
                    is_good = false;
                    break;
                }
            }
            if(is_good){
                number = j;
                found = true;
                break;
            }
            digits.clear();
        }
        if(found == true){
            cout << number << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}