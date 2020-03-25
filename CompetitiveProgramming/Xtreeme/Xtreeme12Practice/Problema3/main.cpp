#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>

using namespace std;


vector<pair<char,char>>TP_left;
vector<pair<char,char>>TP_Right;


bool back[2000][2000];

bool output_back[2000][2000];


string borrarValor(string var,char delVal){
    int del_1 = var.find(delVal);
    if(del_1 != -1){
        var.erase(var.begin()+del_1);
    }
    return var;
}
string borrarPar(string var, pair<char,char> delPair){
    string aux;
    string ans;
    aux = borrarValor(var,delPair.first);
    ans = borrarValor(aux,delPair.second);
    return ans;
}

int diffDeUnPar(string var,pair<char,char> pair2delete) {
    string aux;
    aux = borrarPar(var, pair2delete);
    int pos = aux.find('-');
    string var_left = aux.substr(0, pos);
    string var_right = aux.substr(pos + 1, aux.size() - 1 - pos);
    return var_left.size() - var_right.size();
}

void LoadCounterexamples(vector<string>& pesaje, pair<char,char>first_pair,pair<char,char>second_pair){
    bool isContraej=true;
    vector<bool> res_in_pasajei;
    for(int i = 0 ; i < pesaje.size() ; i++){
        if(diffDeUnPar(pesaje[i],first_pair)==diffDeUnPar(pesaje[i],second_pair)){
            res_in_pasajei.push_back(true);
        }else if(diffDeUnPar(pesaje[i],first_pair) > 0 && diffDeUnPar(pesaje[i],second_pair) > 0){
            res_in_pasajei.push_back(true);
        }else if(diffDeUnPar(pesaje[i],first_pair) < 0 && diffDeUnPar(pesaje[i],second_pair) < 0) {
            res_in_pasajei.push_back(true);
        }else{
            res_in_pasajei.push_back(false);
        }
    }
    for(int i = 0 ; i< res_in_pasajei.size() ; i++ ){
        isContraej= isContraej&& res_in_pasajei[i];
    }

    char a = first_pair.first;
    char b = first_pair.second;
    char c = second_pair.first;
    char d =  second_pair.second;
    if( a<b  &&  a<=c   && c < d && first_pair!=second_pair){
        if(isContraej){
            TP_left.push_back(first_pair);
            TP_Right.push_back(second_pair);
        }
    }

    return;
}



int main() {
    string line;
    getline(cin,line);
    unsigned int limit = line.find(",",0);
    //cin >> n;
    //cin >> m;
    int n = stoi(line.substr(0,limit));
    int m = stoi(line.substr(limit+1,line.length()-limit));
    vector <string> pesajes;
    for(int i = 0; i< m ; i++){
        string aux;
        cin >> aux;
        pesajes.push_back(aux);
    }

    //cout << "GENERACION DE PARES " << endl;

    vector<pair<char,char>>comb;
    for(char i = 'A' ;   i < 'A' + n  ; i++){
        for(char j = i+1 ; j < 'A'+ n ; j++){
            if(back[i][j]==0 && back[j][i]==0) {
                comb.push_back(pair<char,char>(i,j));
                back[i][j]=1;
                back[j][i]=1;
                //cout << pair<char,char>(i,j).first  << pair<char,char>(i,j).second << endl;
            }
        }
    }

    for(int i = 0 ; i < comb.size() ; i++){
        for( int j = i ; j < comb.size() ; j++){
            char a = comb[i].first;
            char b = comb[i].second;
            char c = comb[j].first;
            char d =  comb[j].second;
            if( a<b  &&  a<=c   && c < d && comb[i]!=comb[j]) {
                LoadCounterexamples(pesajes,comb[i],comb[j]);
            }
        }
    }


/*
    string tst = "ADE-BCG";

    LoadCounterexamples(pesajes,pair<char,char>('A','B'),pair<char,char>('A','D'));
*/


    for(int i =0 ; i < TP_left.size() ; i++ ) {
        /*bool marked_left = 0;
        bool marked_right = 0;

        if(output_back[TP_left[i].first][TP_left[i].second] ==0 && output_back[TP_left[i].second][TP_left[i].first] == 0 ){
            output_back[TP_left[i].first][TP_left[i].second] = 1;
            output_back[TP_left[i].second][TP_left[i].first] = 1;
            marked_left = 1;

        }
        if(output_back[TP_Right[i].first][TP_Right[i].second] ==0 && output_back[TP_Right[i].second][TP_Right[i].first]){
            output_back[TP_Right[i].first][TP_Right[i].second] = 1;
            output_back[TP_Right[i].second][TP_Right[i].first] = 1;
            marked_right = 1;
        }
        if(!marked_left && !marked_right){*/
            cout << TP_left[i].first << TP_left[i].second << "=" << TP_Right[i].first << TP_Right[i].second << endl;
        //}
    }
    return 0;
}
