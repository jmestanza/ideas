#include <bits/stdc++.h>
double EPS = 1e-9;
double PI = acos(-1);
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
#define EXTRA 10
using namespace std;

// ACA ARRIBA NO SE TOCA NUNCA
//--------------------------------------------------------


//**********************
// COMPILATION SWITCHES
//**********************

#define READY_TO_UPLOAD
//#define USE_MATRIX
//#define USE_ARR





#ifndef READY_TO_UPLOAD
#include <windows.h>
string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    string aux;
    aux = string( buffer ).substr( 0, pos);
    pos = aux.find_last_of( "\\/" );
    return aux.substr(0,pos);
}
#endif

#ifdef USE_MATRIX
    #define MAX_M 5*10000
    #define MAX_N 5*10000
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
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;


#define F first;
#define S second;
#define PB push_back;
#define MP make_pair;

//v.PB(MP(y1, x1));
//v.PB(MP(y2, x2));
//int d = v[i].F+v[i].S;
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
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
static inline string IntToString(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}
static inline LL StringToInt(string a)
{
    char x[100];
    LL res;
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
//    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
//    os << "]";
    return os;
}

ostream& operator<<(ostream& os, const vector<pii>& v)
{
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return os;
}

bool operator==( pii& a,  pii& b)
{
    return (a.first==b.first)&&(a.second==b.second);
}
pii operator+( pii& a,  pii& b)
{
    return mp(a.first+b.first,a.second+b.second);
}
void operator+=( pii& a,  pii& b)
{
    a.first += a.first + b.first;
    a.second += a.second + b.second;
}


// RECORDAR:
// print de vectores y vector de vectores esta hecho (cout<<)
// print de array y matriz tambien (print_arr<int>(arr,len), print_mat<int>(mat,m,n))

//******************
// GLOBAL VARIABLES
//******************

//vvi ans;

pii N_ = mp(-1,0);
pii W_ = mp(0,-1);
pii E_ = mp(0,1);
pii S_ = mp(1,0);


bool find(vector<pii>& harc_mat,pii &aux){
    bool found = false;
    FOR(i,0,harc_mat.size()){
        if(harc_mat[i]==aux){
            found = true;
            break;
        }
    }
    return found;
}
LL hash_fun(LL k1, LL k2){
    LL sum1 = k1+k2;
    LL sum2 = sum1+1;
    LL mult = sum1*sum2;
    LL div = mult/2;
    LL res = div + k2;
    return  res;
}
void advance(unordered_map<LL,LL>& memory, pii& direct, pii &pos){
    pii aux = pos + direct;
    if(memory.find(hash_fun(aux.first,aux.second)) == memory.end()){
        pos = mp(aux.first,aux.second);
    }else{
        while(!(memory.find(hash_fun(aux.first,aux.second)) == memory.end())){
            aux =  aux + direct;
        }
        pos = mp(aux.first,aux.second);
    }
    memory[hash_fun(pos.first,pos.second)] = 1;
}
int main() {
#ifndef READY_TO_UPLOAD
    OPEN(ExePath()+"\\problem");
#endif
    int t, N, R, C , SR, SC;
    vvi ans;
    vi aux;
    string str;
    cin >> t; // t hasta 100
    pii pos;
    unordered_map<LL,LL> memory;
//    vvi harc_mat = vector<vi>(5*10000+EXTRA,vi(5*10000+EXTRA,0));
//  es demasiado para una matriz!
    TC(t){
        cin>> N >> R >> C >> SR >> SC;
        cin >> str;
        pos.first = SR;
        pos.second = SC;
        memory[hash_fun(pos.first,pos.second)] = 1;
        FORN(j,1,N){
            if(str[j-1] == 'N') {
                advance(memory,N_,pos);
            }else if(str[j-1] == 'W'){
                advance(memory,W_,pos);
            }else if(str[j-1] == 'E'){
                advance(memory,E_,pos);
            }else if(str[j-1] == 'S'){
                advance(memory,S_,pos);
            }
        }
        aux.pb(pos.first);
        aux.pb(pos.second);
        ans.pb(aux);
        aux.clear();
        memory.clear();
    }

    for(int t = 0 ; t<ans.size(); t++){
        cout << "Case #" << t + 1 << ": " << ans[t] << endl;
    }
    return 0;
}
