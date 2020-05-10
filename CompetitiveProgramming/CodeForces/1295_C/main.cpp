#include <bits/stdc++.h>
using namespace std;

double EPS = 1e-9;
double PI = acos(-1);
int INF = 1000000005;
long long INFF = 1000000000000000005LL;

//--------------------------------------------------------
// COMPILATION SWITCHES

#define READY_TO_UPLOAD
//#define USE_MATRIX
//#define USE_ARR


//--------------------------------------------------------


#ifndef USE_MATRIX
    #define EXTRA 10
    #define MAX_M 10
    #define MAX_N 10
    int harc_mat[MAX_M+EXTRA][MAX_N+EXTRA];
    template<class T>
    void print_mat(T mat[MAX_M+EXTRA][MAX_N+EXTRA],  int row,  int col){
        for(int i = 0 ; i< row ; i++) {
            for(int j = 0 ; j< col ; j++){
                cout <<  mat[i][j]  << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
#endif

#ifndef USE_ARR
    #define ARR_LEN 5
    int harc_arr[ARR_LEN+EXTRA];
    template <typename T>
    void print_arr(T arr[ARR_LEN+EXTRA], unsigned int len){
    cout << "[";
    for(int i = 0 ; i< len ; i++) {
        cout <<  arr[i] ;
        if(i != ARR_LEN-1) cout << ", ";
    }
    cout << " ]";
    cout << endl;
}
#endif


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;


#define pb push_back
#define mp make_pair

int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

static inline string IntToString(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
static inline ll StringToInt(string a)
{
    char x[100];
    ll res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}
static inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}
static inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
    return s;
}
static inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    return s;
}
static inline void OPEN(string s)
{
#ifndef READY_TO_UPLOAD
    freopen((s + ".txt").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

template <class myType>
void print_ans(myType& ans) {
    for(int i = 0 ; i<ans.size() ; i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << endl;
    }
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

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

//******************
// GLOBAL VARIABLES
//******************

int main() {
    OPEN("C:\\Users\\joa-m\\ideas\\Generic\\problem");
    int t;
    vi ans;

    unordered_map<string,int> look_up;

    string Z = "";
    string T = "";
    int pos;
    int max_pos;
    bool isBad;
    cin >> t; // t hasta 100
    TC(t){
        cin >> Z >> T;
        isBad = true;
        max_pos = LCS(Z,T, look_up);
        int i;
        for(i = 0 ; i<Z.size() && !isBad; ){
            max_pos = LCS(Z.substr(i,Z.size()),T.substr(i,T.size()), look_up);
            while(i < max_pos && !isBad){
                if(Z[i] != T[i]){
                    isBad = true;
                }
            }
            if(!isBad){
                i+=max_pos; 
            }
        }
        cout << "llegue bien hasta: " << i << endl;
        look_up.clear();
    }
    print_ans(ans);
    return 0;
}
