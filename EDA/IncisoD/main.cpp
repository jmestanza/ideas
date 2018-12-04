#include <iostream>
using namespace std;

int& f(){
    int a = 0;
    return a;
}


void main() {
    int a = 1;
    a = f();
    cout << a;
}

// no compila