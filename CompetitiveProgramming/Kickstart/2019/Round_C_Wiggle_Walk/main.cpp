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

//#define READY_TO_UPLOAD
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


template <class T>
class point {
public:
    T first, second;
    point(T first_ = 0,T second_ = 0){
        this->first= first_;
        this->second = second_;
    }
    point make_pair(T first_ = 0,T second_ = 0){
        return point(first_,second_);
    }
    T operator [] (int i){
        if(i == 0){
            return this->first;
        }else if(i==1){
            return this->second;
        }
    }
    void operator = (const point& v){
        this->first = v.first;
        this->second = v.second;
    }
    point operator + (point &c1)
    {
        return point(this->first + c1.first,this->second + c1.second);
    }
    point& operator+=(const point& obj){
        this->first += obj.first;
        this->second += obj.second;
        return *this;
    }
    point operator - ( point const &obj)
    {
        point res;
        res.first -= obj.first;
        res.second -= obj.second;
        return res;
    }
    point operator*(point obj)
    {
        point res;
        res.first = this->first * obj.first;
        res.second = this->second * obj.second;
        return res;
    }
    point operator*(T obj) {
        point res;
        res.first = this->first * obj;
        res.second = this->second * obj;
        return res;
    }
    friend ostream & operator << (ostream &out, const point &c)
    {
        out << c.first << " " << c.second;
        return out;
    }
};



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
typedef vector<unordered_map<LL,LL>> vmap;
typedef point<LL> p_ll;
typedef vector<p_ll> vp_ll;
typedef vector<vp_ll> vvp_ll;


#define fi first
#define se second

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

ostream& operator<<(ostream& os, const pii& v)
{
    os << v.first << " " << v.second;
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
pii operator-( pii& a,  pii& b)
{
    return mp(a.first-b.first,a.second-b.second);
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

int main() {
#ifndef READY_TO_UPLOAD
    OPEN(ExePath()+"\\problem");
#endif
    int t, N, R, C , r, c;
    map< pii, bool > visited;
    vector <pii> ans;
    vi aux;
    string s;
    cin >> t; // t hasta 100

//    vvi harc_mat = vector<vi>(5*10000+EXTRA,vi(5*10000+EXTRA,0));//  es demasiado para una matriz!

    TC(t){
        cin>> N >> R >> C >> r >> c;
        cin >> s;

        visited[mp(r, c)] = true;

        for (int i = 0; i < N; i++) {
            if (s[i] == 'N')
                while (visited[mp(r, c)])
                    r--;
            if (s[i] == 'E')
                while (visited[mp(r, c)])
                    c++;
            if (s[i] == 'S')
                while (visited[mp(r, c)])
                    r++;
            if (s[i] == 'W')
                while (visited[mp(r, c)])
                    c--;

            visited[mp(r, c)] = true;
        }
        ans.push_back(mp(r,c));
        visited.clear();
    }
    for(int t = 0 ; t<ans.size(); t++){
        cout << "Case #" << t + 1 << ": " << ans[t] << endl;
    }
    return 0;
}
