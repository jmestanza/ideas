#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<double,double>> vpd;
typedef pair<double,double> pdd;

int check_ineq_rojos(vpd color, pdd w){
    int cnt = 0;
    double x,y;
    for(int i = 0 ; i<color.size() ; i++){
        x = color[i].first;
        y = color[i].second;
        if(w.first*x + w.second*y>= 0){ // si entra o esta por entrar
            cnt++;
        }
    }
    return cnt;
}

int check_ineq_blues(vpd color, pdd w){
    int cnt = 0;
    double x,y;
    for(int i = 0 ; i<color.size() ; i++){
        x = color[i].first;
        y = color[i].second;
        if(w.first*x + w.second*y<= 0){ // si entra o esta por entrar
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int tc,n,cnt_rojos,cnt_blues, m,clase;
    vpd rojos;
    vpd blues;
    double x,y;
    pdd w = pair<double,double>(1.0,1.0);
    cin >> tc;
    for(int i = 0 ; i < tc; i++){
        rojos.clear();
        blues.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> x >> y >> clase;
            if (clase == 1) rojos.push_back(pair<double, double>(x, y));
            else blues.push_back(pair<double, double>(x, y));
        }
        bool separable = false;
        for(double z1 = -100 ; z1 < 100 && !separable; z1+=0.5){
            for(double z2 = -100 ; z2 < 100 && !separable; z2+=0.5){
                w.first  = z1;
                w.second = z2;
                cnt_rojos = check_ineq_rojos(rojos,w);
                cnt_blues = check_ineq_blues(blues,w);

                if(cnt_rojos == rojos.size() && cnt_blues == 0){
                    separable = true;
                }
                
                if(cnt_blues == blues.size() && cnt_rojos == 0){
                    separable = true;
                }
            }
        }
        
        cout << "rojos:" << cnt_rojos << endl;
        cout << "blues:" << cnt_blues << endl;

        if(separable) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
