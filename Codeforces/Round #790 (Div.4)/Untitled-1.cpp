// URL: https://codeforces.com/contest/1676/problem/H1

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;

#define fore(x,vc) for(auto &x: vc)
#define forr(i,a,b) for(int i = a;i <= b;++i)
#define forn(i,n) for(int i = 0; i < int(n);++i)
#define ford(i,n) for(int i = int(n) - 1;i >= 0;i--)

#define sz(x) int(x.size())
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void _print(int x) {cerr << x;}
void _print(long x) {cerr << x;}
void _print(long long x) {cerr << x;}
void _print(unsigned x) {cerr << x;}
void _print(unsigned long x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(const char *x) {cerr << '\"' << x << '\"';}
void _print(const string &x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template<typename A,typename B>void _print(const pair<A,B>& p);
template<typename A,typename B,typename C> void _print(const tuple<A,B,C>& tp);
template<typename A,typename B,typename C,typename D>void _print(const tuple<A,B,C,D>& tp);
template<typename A>void _print(const A &x);

template<class A,class B,class C>istream&operator>>(istream&in,tuple<A,B,C>&tp){return in>>get<0>(tp)>>get<1>(tp)>>get<2>(tp);}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&p){return in>>p.first>>p.second;}
template<class A>istream&operator>>(istream&in,vector<A>&x){for(A &i:x)in>>i;return in;}
template<typename A,typename B>
void _print(const pair<A,B>& p){cerr<<"(";_print(p.first);cerr<<", ";_print(p.second);cerr<<')';}
template<typename A,typename B, typename C>
void _print(const tuple<A,B,C>& tp){cerr <<"(";_print(get<0>(tp));cerr<<", ";_print(get<1>(tp));cerr<<", ";_print(get<2>(tp));cerr<<')';}
template <typename A,typename B, typename C,typename D>
void _print(const tuple<A,B,C,D>& tp){cerr<<"(";_print(get<0>(tp));cerr<<", ";_print(get<1>(tp));cerr<<", ";_print(get<2>(tp));cerr<<", ";_print(get<3>(tp));cerr<<')';}
template<typename A>
void _print(const A &x){int f=0;cerr<<'{';for(auto i:x)cerr<<(f++?", ":""),_print(i);cerr<<"}";}
void dbg_out(){cerr<<endl;}
template<typename Head, typename... Tail>
void dbg_out(Head H,Tail... T){cerr<< " ";_print(H);dbg_out(T...);}

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;
const int MX = 2e5 + 5;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int>& a) : FenwickTree(a.size()) {
        for(size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
	int n;
	cin >> n;
	
	vi a(n);
	for(int &x: a) {
		cin >> x;
		x -= 1;
	}
	
	FenwickTree ft(n);
	dbg(a);
	for(int x: a) {
		ft.add(x,1);
	}
	
	dbg(ft.bit);
	
	ll ans = 0;
	for(int x: a) {
		dbg(x);
		ft.add(x,-1);
		dbg(ft.bit);
		ans += ft.sum(x);
		cout << ans << endl;
	}
	cout << ans << nl;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;
	cin >> tc;
	while(tc--)
		solve();

	return 0;
}
