#include <iostream>
using namespace std;

class top{
public:
    int a;
    top(int i){a=i;};
};
class bottom: public top{
public:
    int b;
    bottom():top(5){a=0; b=0;};
};


int main() {
    bottom b;
    cout << b.a << endl << b.b << endl;
}
