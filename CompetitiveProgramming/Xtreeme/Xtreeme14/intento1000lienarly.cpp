#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<double,double>> vpd;
typedef pair<double,double> pdd;

int check_ineq_rojos(vpd color, double m){
    int cnt = 0;
    double x,y;
    for(int i = 0 ; i<color.size() ; i++){
        x = color[i].first;
        y = color[i].second;
        if(m*x + y<= 0){ // si entra o esta por entrar
            cnt++;
        }
    }
    return cnt;
}

int check_ineq_blues(vpd &color, double m){
    int cnt = 0;
    double x,y;
    for(int i = 0 ; i<color.size() ; i++){
        x = color[i].first;
        y = color[i].second;
        if(m*x + y<= 0){ // si entra o esta por entrar
            cnt++;
        }
    }
    return cnt;
}

bool check_separable(vpd &rojos,vpd &blues){
    int cnt_blues = 0;
    int cnt_rojos = 0;
    bool separable = false;
    for(double m = -25; m<=25; m+=0.01){
        cnt_rojos = check_ineq_rojos(rojos,m);
        cnt_blues = check_ineq_blues(blues,m);
    }
    if(cnt_rojos == rojos.size() && cnt_blues == 0) separable = true;
    if(cnt_blues == blues.size() && cnt_rojos == 0) separable = true;
    return separable;
}


int main() {
    int tc,n,cnt_rojos,cnt_blues,clase;
    vpd rojos,blues,rojos_rotated,blues_rotated;
    double x,y;
    pdd w = pair<double,double>(1.0,1.0);
    cin >> tc;
    for(int i = 0 ; i < tc; i++){
        rojos.clear();
        blues.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> x >> y >> clase;
            if (clase == 1) {
                rojos.push_back(pair<double, double>(x, y));
                rojos_rotated.push_back(pair<double, double>(x, y));
            } else {
                blues.push_back(pair<double, double>(y, -x));
                blues_rotated.push_back(pair<double, double>(y, -x));
            }
        }
        bool separable = false;
    
        separable = check_separable(rojos,blues);
        if(!separable){
           separable = check_separable(rojos_rotated,blues_rotated);
        }
    
        if(separable){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
