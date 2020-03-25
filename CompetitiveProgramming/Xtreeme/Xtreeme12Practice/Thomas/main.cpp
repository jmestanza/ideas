#include <iostream>
#include <vector>
using namespace std;

char memory[400];


void toggle2bits(vector<bool>&num,int pos){
    if(pos+1<=num.size()){
        num[pos]=!num[pos];
        num[pos+1]=!num[pos+1];
    }
}
void printarr(vector<bool>&num, char letter){
    cout << letter << " ";
    for(int i = 0 ; i < num.size() ; i++){
        cout <<  num[i] << " ";
    }
    cout << endl;
}

void  check_mem(vector<bool>&ans,int cnt){
    int auxcnt = cnt;
    while(auxcnt>=0){
        if(memory[auxcnt]=='x'){
            memory[auxcnt] = 's';
            if(ans[auxcnt+1]==ans[auxcnt]){
                ans[auxcnt]=!ans[auxcnt];
            }
        }
        auxcnt--;
    }
}


int Step(vector<bool>&ans,int& cnt,int ViejoAcierto){

    //leo aciertos1
    printarr(ans,'Q');
    //leo otro acierto2
    int NewAcierto;
    cin >> NewAcierto;
    // aciertos1>aciertos2
    if(ViejoAcierto>NewAcierto){
        toggle2bits(ans,cnt);
        check_mem(ans,cnt);
        cnt ++; // fue mala
        cnt ++;


    }else if(ViejoAcierto<NewAcierto){
        check_mem(ans,cnt); //ya tengo un acierto asegurar lo que estaba antes
        cnt ++; // la modificacion fue buena
        cnt ++;
        toggle2bits(ans,cnt);
    }else{
        memory[cnt]='x';
        cnt++; // esto significa que el siguiente es el contrario
        toggle2bits(ans,cnt);
    }
    return NewAcierto;
}

int main() {
    //int n=6;
    int n;
    cin >> n;
    vector <bool> ans;
    for(int i = 0; i<n; i++){
        ans.push_back(0);
    }

    int cnt=0;
    printarr(ans,'Q');
    int ViejoAcierto;
    int NewAcierto;
    cin >> ViejoAcierto;

    toggle2bits(ans,cnt);

    while ( cnt<n-1){ // posible falla
        ViejoAcierto= Step(ans,cnt,ViejoAcierto);
    }

    if(ViejoAcierto != n){
        cnt = n - 1;
        ans[n-1]= !ans[n-1];
        printarr(ans,'Q');
        cin >> NewAcierto;
        if(ViejoAcierto>NewAcierto){
            ans[n-1]= !ans[n-1];
            check_mem(ans,cnt);
        }else if(ViejoAcierto<NewAcierto) {
            check_mem(ans, cnt);
        }
    }
    printarr(ans,'A');
    return 0;
}