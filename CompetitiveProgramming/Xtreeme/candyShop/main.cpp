#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[10000+1][10000+1];


long getWays(int n, vector<long> c) {
    // let's make it constructive
    vector<long> ways(n+1, 0);
    ways[0] = 1;

    for(long coin: c){
        for(long i = coin; i < ways.size(); i++){
            ways[i] += ways[i-coin];
        }
    }
    return ways[n];
}

int main() {
    int N,K;
    cin >> N;
    cin >> K;
    vector<pair<int,int>> candy_bags;
    vector<long> coins;

    for (int i = 0; i < N; i++) {
        int bags_count, candies;
        cin >> bags_count;
        cin >> candies;
        candy_bags.push_back(pii(bags_count, candies));
        coins.push_back(candies);
    }


    cout << getWays(K, coins) << endl;

    return 0;
}
