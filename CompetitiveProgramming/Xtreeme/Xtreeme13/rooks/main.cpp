#include <bits/stdc++.h>

using namespace std;

int tablero[10000][10000];

class Pos {       // The class
public:             // Access specifier
    Pos(int x_, int y_){
    this->x = x_;
    this->y = y_;
    }
    int x;        // Attribute (int variable)
    int y;  // Attribute (string variable)
    friend ostream& operator<<(ostream& os, const Pos& pos_arg);

};


struct less_than_py
{
    inline bool operator() (const Pos& p1, const Pos& p2)
    {
        return (p1.y < p2.y);
    }
};

struct less_than_px
{
    inline bool operator() (const Pos& p1, const Pos& p2)
    {
        return (p1.x < p2.x);
    }
};


ostream& operator<<(ostream& os, const Pos& pos_arg)
{
    os << pos_arg.x << ' ' << pos_arg.y ;
    return os;
}

void SwapR(Pos& p1,Pos&p2){ // p1 avanza a p2 y p2 vuelve a p1
    p1.x++;
    p2.x--;
    cout << " " ;
}

int main() {
    int n;
    int x, y;
    cin >> n;
    vector<Pos> rooks;
    vector<Pos> targets;
    vector<int> rooks_y;
    vector<int> rooks_x;
    vector<int> targets_x;
    vector<int> targets_y;

    for( int i =0 ; i < n ; i++){
        cin >> x;
        cin >> y;
        rooks.push_back(Pos(x,y));
        rooks_x.push_back(x);
        rooks_y.push_back(y);
    }
    for( int i =0 ; i < n ; i++){
        cin >> x;
        cin >> y;
        targets.push_back(Pos(x,y));
        targets_x.push_back(x);
        targets_y.push_back(y);
    }

    for ( int i = 0; i< rooks.size() ; i++){
        cout << rooks[i] << endl;
    }
    for ( int i = 0; i< targets.size() ; i++){

         cout << targets[i] << endl;
    }

    sort(rooks.begin(), rooks.end(), less_than_py());
    sort(targets.begin(), targets.end(), less_than_py());

    cout << "hola thomas xd" << endl;

    /* ORDENAMOS LOS ROOKS Y LOS TARGETS DE MENOR A MAYOR EN EJE Y */
    for ( int i = 0; i< rooks.size() ; i++){
        cout << rooks[i] << endl;
    }
    for ( int i = 0; i< targets.size() ; i++){

        cout << targets[i] << endl;
    }
    /* ahora pensamos como son los movimientos, desde la mas lejana de Rooks (de la izquierda)
     * hasta la mas lejana(de la derecha) de los targets*/

    // accedemos al tablero 5000,5000 = 0,0


    return 0;
}