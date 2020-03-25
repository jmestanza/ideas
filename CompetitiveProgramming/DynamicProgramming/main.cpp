#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, unordered_map<string,int>  &lookup){
    if (X.size() == 0 || Y.size() == 0)
        return 0;

    string key = to_string(X.size()) + "|" + to_string(Y.size());
    if(lookup.find(key) == lookup.end()){ // if not found solved problem
        // let's consider what happens when x and y end with the same char
        // we call LCS(X[:n-1],Y[:n-1])+ X/Y.back() because we found a match, and sum the char val
        if( X.back() == Y.back() )
            lookup[key] = LCS(X.substr(0,X.size()-1), Y.substr(0, Y.size()-1), lookup) + 1;
        else
            // now consider they do not end with the same char
            // we have to delete last char and keep looking, but there are two last char and
            // they are different. So here enters the CHOICE, and we want the LONGEST common
            // subsequence, so we want the result to be big, hence we use max
            lookup[key] = max(LCS(X.substr(0,X.size()-1),Y,lookup),LCS(X,Y.substr(0,Y.size()-1),lookup));
    }
    return lookup[key];
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABA";

    unordered_map<string,int> look_up;

    cout << LCS(X,Y, look_up) << endl;
    return 0;
}
