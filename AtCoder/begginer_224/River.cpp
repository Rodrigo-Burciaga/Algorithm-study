#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fore(x,v) for(auto x: v)
#define gauss(n) ((n) * ((n) + 1)) / 2
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

void solve() {
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; 
	ll sum = 0;
	ll temp;
	for (int i = 0; i < T; ++i){
		cin >> temp;
		sum += temp;
	}

	return 0;
}
