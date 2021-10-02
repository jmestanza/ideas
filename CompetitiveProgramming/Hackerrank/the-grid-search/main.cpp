#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */
bool is_subgrid_valid(int i,int j, vector<string> G, vector<string> P){
    int matches = 0;
    int k = 0;
    for(int l = i; l < min(i+P.size(),G.size()) ; l++){
        string curr_str = G[l].substr(j, P[k].size());
        if(curr_str == P[k]){ matches++;}
        k++;
    }
    return matches == P.size();
}

vector<pair<int, int>> find_candidates( vector<string> &G,  vector<string> &P){
    vector<pair<int,int>> candidates;
    // first find in a row, how many

    for (int i = 0; i < G.size(); i++) {
        string curr_str = G[i];
        bool first_time = true;
        size_t col = 0; // random init value
        while (col != string::npos) {
            if(first_time){
                col = curr_str.find(P[0]);
                first_time = false;
            }else{
                col = curr_str.find(P[0], col + 1);
            }
            if (col != string::npos) {
                candidates.emplace_back(i, col);
            }
        }
    }
    return candidates;
}

string gridSearch(vector<string> G, vector<string> P) {
    bool found = false;
    size_t col = 0;

    string ans;

    vector<pair<int,int>> candidates = find_candidates(G, P);

    if ( std::any_of(candidates.begin(), candidates.end(), [&G, &P](pair<int,int> candidate){
        int i = candidate.first;
        int j = candidate.second;
        return is_subgrid_valid(i, j, G, P);
    }) ){
        ans = "YES";
    } else {
        ans = "NO";
    }
//    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
