#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int cum_sum_arr[100+10][10000+10];
int main(){
    int t, n, p, s, hours, act_hours;
    string ans;
    cin >> t;
    vi students;
    for(int i = 0; i<t ; i++){
        cin >> n >> p; // number of students, and students need to pick
        for(int j = 0 ; j < n ; j ++){
            cin >> s;
            students.push_back(s);
        }
        sort(students.begin(), students.end(),greater<int>());
        for(int j = 0; j < students.size() ; j++){
            if(j==0) cum_sum_arr[i][j] = students[j];
            else cum_sum_arr[i][j] = students[j] + cum_sum_arr[i][j-1];
        }
        hours = INT_MAX;
        for(int l = 0 ; l < students.size()-p + 1; l ++){
            // el ultimo de iterar de a cachos de tamano p es (l+p-1)
            if(l == 0) act_hours = cum_sum_arr[i][l + p - 1];
            else act_hours = cum_sum_arr[i][l + p - 1] - cum_sum_arr[i][l - 1];
            if((p*students[l]-act_hours) < hours) hours = p*students[l]-act_hours;
        }
        students.clear();
        cout << "Case #" << i+1 << ": "<< hours << endl;
    }
    return 0;
}