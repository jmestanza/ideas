#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int equal(vector<int> arr) {
    int max = *max_element(std::begin(arr), std::end(arr));
    int min = *min_element(std::begin(arr), std::end(arr));
    int n = max-min;
    vector<int> results(n+1,0);
    vector<int> pieces{1,2,5};
    for(int piece: pieces){
        if(piece <= n)
        results[piece] = 1;
    }
    for(int i = 1; i< n+1 ; i++){
        if (std::find(pieces.begin(), pieces.end(),i)!=pieces.end()){
        // if found, do nothing
        }else{
            vector<int> copied_pieces = pieces;
            auto new_end = std::remove_if(copied_pieces.begin(), copied_pieces.end(),
                                          [i,n](int piece)
                                          { return i - piece < 0; });
            copied_pieces.erase(new_end, copied_pieces.end());
            int max_possible = *max_element(std::begin(copied_pieces), std::end(copied_pieces));
            results[i] = 1 + results[i-max_possible];
        }
    }
    cout << results[n] << endl;
    return results[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

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
