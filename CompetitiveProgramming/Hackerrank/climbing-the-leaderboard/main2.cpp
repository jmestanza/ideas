#include <bits/stdc++.h>
using namespace std;
int main () {
//  def de lower bound y upper bound:
//  https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound
//  literalmente es donde lo insertarias sin alterar el orden
    vector<int> v{1,2,4,5,6};
    vector<int>::iterator low;
    low=std::lower_bound (v.begin(), v.end(), 3);
    cout << "lower_bound at position " << (low- v.begin()) << '\n';
    // si no esta en el arreglo -> devuelve donde lo insertaria
    low=std::lower_bound (v.begin(), v.end(), 6);
    cout << "lower_bound at position " << (low- v.begin()) << '\n';  // si es igual devuelve el mismo, ok
    low=std::lower_bound (v.begin(), v.end(), 7);
    cout << "lower_bound at position " << (low- v.begin()) << '\n';

    vector<int> v2{1,2,4,5,6}; // 1, 2, 4, 5, 6
    low=std::lower_bound (v2.begin(), v2.end(), 3);
    cout << int(low-v2.begin()) << endl; // inserting it at 2, moves the rest to the right
    v2.insert(low, 3); // 1, 2, 3, 4, 5, 6

    vector<int> v3{1,2,4,5,6}; // 1, 2, 4, 5, 6
    low=std::lower_bound (v3.begin(), v3.end(), 2);
    cout << int(low-v3.begin()) << endl; // inserting it at 2, moves the rest to the right
    v2.insert(low, 2); // 1, 2, 3, 4, 5, 6

    return 0;
}