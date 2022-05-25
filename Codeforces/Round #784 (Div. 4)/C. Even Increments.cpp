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

const int MOD = 1e9 + 7;
const char nl = '\n';
const ll INF = 1e18;

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> numeros(n);
	vector<int> copy;
	int pares = 0, impares = 0;
	for(auto &num: numeros){
		cin >> num;
		if(num % 2 == 0) pares++;
		else impares++;
	}
	
	if(pares == 0 or impares == 0){
		cout << "YES" << endl;
		return;
	}
	
	copy = numeros;
	pares =  impares = 0;
	for(int i = 0; i<n; i+=2){
		copy[i]++;
	}
	
	
	for(auto &num: copy){
		if(num % 2 == 0) pares++;
		else impares++;
	}
	

	if(pares == 0 or impares == 0){
		cout << "YES" << endl;
		return;
	}
	
	copy  = numeros;
    pares =  impares = 0;

	
	for(int i = 1; i<n; i+=2){
		copy[i]++;
	}
	
	
	for(auto &num: copy){
		if(num % 2 == 0) pares++;
		else impares++;
	}
	
	if(pares == 0 or impares == 0){
		cout << "YES" << endl;
		return;
	}
	
	
	
	cout << "NO" << endl;
		
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
