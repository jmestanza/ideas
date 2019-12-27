#include <bits/stdc++.h>
using namespace std;

class pos {
public :
    int x;
    int y;
    pos(){
        x=0;
        y=0;
    }
    pos(int _x,int _y) {
        x = _x;
        y = _y;
    }

    bool operator ==(pos &another){
        if(another.x == this->x && another.y == this->y){
            return true;
        }else{
            return false;
        }
    }
    void operator +=(pos& aux){
        this->x+=aux.x;
        this->y+=aux.y;
    }
    pos operator +(pos& number2){
        pos aux;
        aux.x=this->x+number2.x;
        aux.y=this->y+number2.y;
        return aux;
    }
    void operator =(pos number2){
        this->x=number2.x;
        this->y=number2.y;
    }
};

struct fire_desc{
    int ti;
    fire_desc( int _ti){
        ti=_ti;
    }

};


int ans;
int pos_registry[500][500];
char repetido[500][500][3][3][31]; //init pos init dir nivel


vector <pos>right_dir;
vector <pos>left_dir;
int n;

void setDirections(void){
    right_dir.push_back(pos(0,1));
    right_dir.push_back(pos(1,1));
    right_dir.push_back(pos(1,0));
    right_dir.push_back(pos(1,-1));
    right_dir.push_back(pos(0,-1));
    right_dir.push_back(pos(-1,-1));
    right_dir.push_back(pos(-1,0));
    right_dir.push_back(pos(-1,1));

    left_dir.push_back(pos(0,1));
    left_dir.push_back(pos(-1,1));
    left_dir.push_back(pos(-1,0));
    left_dir.push_back(pos(-1,-1));
    left_dir.push_back(pos(0,-1));
    left_dir.push_back(pos(1,-1));
    left_dir.push_back(pos(1,0));
    left_dir.push_back(pos(1,1));
}

void next_step(vector <fire_desc>&fire, pos init_pos,pos direction, int ti_num){
    if(repetido[init_pos.x][init_pos.y][direction.x+1][direction.y+1][ti_num]==0){
        repetido[init_pos.x][init_pos.y][direction.x+1][direction.y+1][ti_num]=1;
    }else{
        return;
    }
    pos pos_aux=init_pos;
    for(int i = 1; i<= fire[ti_num].ti; i++,pos_aux.x+= direction.x , pos_aux.y+= direction.y){
        if(pos_registry[pos_aux.x][pos_aux.y]==0){
            pos_registry[pos_aux.x][pos_aux.y]=1;
            ans++;
        }
        if(i==fire[ti_num].ti){
            if(ti_num==n){
                return;
            }
            pos next_right_dir;
            pos next_left_dir;

            for(int k=0; k<=7;k++) {
                if(direction == right_dir[k]){
                    next_right_dir = pos(right_dir[(k+1)%8].x, right_dir[(k+1)%8].y);
                }
                if(direction == left_dir[k]){
                    next_left_dir = pos(left_dir[(k+1)%8].x, left_dir[(k+1)%8].y);
                }
            }

            pos next_init_left_pos = pos_aux+next_left_dir;
            pos next_init_right_pos= pos_aux+next_right_dir;

            next_step(fire,next_init_left_pos,next_left_dir,ti_num+1);
            next_step(fire,next_init_right_pos,next_right_dir,ti_num+1);
        }
    }
}


int main() {

    ans=0;
    setDirections();

    cin >> n;
    vector <fire_desc>fire;
    fire.push_back(fire_desc(0));

    for(int i =0 ; i <n ; i++){
        int aux_ti;
        cin >> aux_ti;
        fire.push_back(fire_desc(aux_ti));

    }

    pos init_pos = pos(250,250);
    pos init_dir = pos(0,1);
    int c = 1;

    next_step(fire,init_pos,init_dir,c);

    cout << ans << endl;

    return 0;
}

