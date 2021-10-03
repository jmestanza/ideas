#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

typedef struct {
    long num;
    vector<vector<int>> arr;
    bool possible;
}result;

map<int, result> memo;
vector<long> c;

result getCombinations(int n){
    if(!(memo.find(n) == memo.end())) return memo[n];
    if(n == 0){
        result ans;
        ans.arr.emplace_back();
        ans.possible = true;
        return ans;
    }
    if(n<0){
        result ans;
        ans.possible = false;
        return ans;
    }

    result combinations;

    for (long currNum: c) {
        int currSum = n - currNum;
        result res = getCombinations(currSum);
        if(res.possible){
            for (vector<int> r: res.arr) {
                r.push_back(currNum);
                combinations.arr.push_back(r);
                combinations.possible = true;
            }
        }
    }
    memo[n] = combinations;

    return combinations;
}

long delete_duplicate_combination(vector<vector<int>> &v){
    long count = 0;
    for(long long i = static_cast<long long>(v.size())-1; i >= 0; --i)
    {
        for(std::size_t j = 0; j < static_cast<std::size_t>(i); ++j)
        {
            if(std::is_permutation(v[static_cast<std::size_t>(i)].begin(), v[static_cast<std::size_t>(i)].end(), v[j].begin(), v[j].end()))
            {
                count++;
//                v.erase(v.begin()+i);
                break;
            }
        }
    }
    return count;
}

long getWays(int n) {
    result res = getCombinations(n);
    long permutations = delete_duplicate_combination(res.arr);
    return res.arr.size()-permutations;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    c = vector<long> (m,0);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n);

    fout << ways << "\n";

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
