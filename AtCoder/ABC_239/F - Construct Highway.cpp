#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

//#include<bits/stdc++.h>


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


struct DSU{
	
	vector<int> parent;
	vector<int> sz;
	
	DSU(int n): parent(n), sz(n,1) {
		for(int i = 0; i<n; ++i)
			parent[i] = i;
	}
	
	int find(int u){
		return parent[u] = (parent[u] == u ? u : find(parent[u]));
	}
	
	bool union_find(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if(pu != pv) {
			if(sz[pu] < sz[pv])
			swap(pu, pv);
			sz[pu] += sz[pv];
			parent[pv] = pu;	
			return true;
		} 
		
		return false;
	}
	
	void print(){
		for(int i = 0; i< (int)parent.size(); i++){
			cout << "parent[" << i << "]= " << parent[i] << endl; 
		}
	}
	
	
	bool same_set(int a, int b){
		return find(a) == find(b);
	}
	
};

void solve() {
	int N,M;
	cin >> N >> M;
	vector<int> d(N);
	ll sum = 0;
	for(auto &h: d){
		cin >> h;
		sum += h;
		
	}
	
	
	if(sum != (2*N-2)){
		cout << -1 << endl;
		return;
	}
	
	DSU highways(N);
	
	forn(i, M){
		int u, v; cin >> u >> v;
		u--; v--;
		if(!highways.union_find(u,v)){
			cout << -1 << endl;
			return;
		}
		d[u]--;
		d[v]--;
	}
	
	vector<vector<int>> temp(N);
	forn(i, N){
		if(d[i] < 0){
			cout << -1 << endl;
			return;
		}
		
		forn(j,d[i]){
			temp[highways.find(i)].pb(i);
		}
	}
	
	vector<vector<int>> c2;
	vector<int> c1;
	
	for(auto c: temp){
		
		if(len(c) == 1){
			c1.pb(c[0]);
		}
		
		if(len(c) > 1){
			c2.pb(c);
		}
	}
	
	debug(c1, c2);
	vector<pair<int,int>> ans;
	for(auto c: c2){
		for(int i = 0; i < len(c)-1; i++){
			if(c1.empty()){
				cout << -1 << endl;
				return;
			}
			ans.pb({c[i], c1.back()});
			c1.pop_back();			
		}
		c1.pb(c.back());
	}	
	
	if(c1.size() != 2){
		cout << -1 << endl;
		return;
	}
	
	
	ans.pb({c1[0], c1[1]});
	
	
	for(auto const &[p,q]: ans){
		cout << p+1 << " " << q+1 << endl;
	}
	
		
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	
		solve();

	return 0;
}
