#include <iostream>
using namespace std;

int main() {
    char*p="algo1";
    p = "algo2";
    cout << p ;
    p[3]="a";
    cout << p << endl;
}
