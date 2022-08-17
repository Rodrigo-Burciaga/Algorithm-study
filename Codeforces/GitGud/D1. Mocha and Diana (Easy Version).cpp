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
	
	void union_find(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if(pu != pv) {
			if(sz[pu] < sz[pv])
			swap(pu, pv);
			sz[pu] += sz[pv];
			parent[pv] = pu;	
		}
	}
	
	void print(){
		for(int i = 0; i< (int)parent.size(); i++){
			cout << "parent[" << i << "]= " << parent[i] << endl; 
		}
	}
	
	bool are_connected(int u, int v){
		return find(u) == find(v);
	}
	
};

void solve() {
	int n, m1, m2; cin >> n >> m1 >> m2;
	DSU mocha(n); DSU diana(n);
	forn(i, m1){
		int u, v; cin >> u >> v;
		u--; v--;
		mocha.union_find(u, v);
	}
	
	forn(i, m2){
		int u, v; cin >> u >> v;
		u--; v--;
		diana.union_find(u, v);
	}
	
	vector<pair<int,int>> ans;
	for(int i = 0; i<n; ++i)
		for(int j = i+1; j<n; ++j){
			if(!mocha.are_connected(i,j) and !diana.are_connected(i, j)){
				mocha.union_find(i,j); diana.union_find(i, j);
				ans.pb({i+1, j+1});
			}
		}
	
	cout << len(ans) << endl;
	for(auto p: ans)
		cout << p.first << " " << p.second << endl;
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

		solve();

	return 0;
}
