#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//#define MAXN int(5e5+20)

void printVec(vector<int>& A){
    cout << endl;
    for(int i = 0 ; i < A.size() ; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
int a[500];
int freq[500];
vector<int> GordosNum;
vector<int> GordosPos[500];
vector<int> MierdasPos[500];

vector<pair<int,int>> uv_list;
int n;


void ArmarGrafo(){
    pair<int,int> uv;
    for(int i = GordosNum.size()-1 ; i>=0 ;i++){
        for(int j = 0 ; j< GordosPos[i].size() ; j++){
            uv.first = GordosPos[i][j];
            uv.second = GordosPos[i][j+1];
            uv_list.push_back(uv);

        }

    }
}

int main(){
    int aux;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> aux;
        a[i]=aux;
        freq[aux]++;
        if(aux>1){
            GordosNum.push_back(aux);
            GordosPos[aux].push_back(i);
        }else{
            MierdasPos[aux].push_back(i);
        }
    }

    sort( GordosNum.begin(), GordosNum.end() );
    GordosNum.erase( unique(GordosNum.begin(), GordosNum.end() ), GordosNum.end() );

    //ArmarGrafo();
    for(int i = 0 ; i < uv_list.size() ; i++){
        cout << uv_list[i].first  << " " << uv_list[i].second  << endl;
    }
    return 0;
}
