#include <iostream>
using namespace std;

void func(long a, long b){
    cout << "long" << endl;
}

void func(double a, double b){
    cout << "double" << endl;
}


int main() {
    int a,b;
    func(a,b);
    return 0;
}

// no compila