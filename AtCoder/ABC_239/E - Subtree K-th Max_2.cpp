#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
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


vector<ll> values;
vector<vector<ll>> tree;


vector< ll> dfs(int pos, int parent, vector<vector<ll>> &subTree){
	
	
	vector<ll> ans = {values[pos]};
	fore(next_pos, tree[pos]){	 
		if(next_pos != parent){
			vector<ll> temp_ans = dfs(next_pos, pos, subTree);
			if(len(temp_ans) + len(ans) <= 20){
				ans.reserve(ans.size() + temp_ans.size());
				ans.insert(ans.end(), temp_ans.begin(), temp_ans.end());
				sort(ans.begin(), ans.end());
			} else {
				fore(te, temp_ans){
					if(len(ans) < 20) {
						ans.pb(te);
						sort(ans.begin(), ans.end()); // se puede cambiar por un inserction sort
					}
					else if(ans[0] < te) {
							ans[0] = te;
							sort(ans.begin(), ans.end()); 						
					}
				}
				
			}
			

		}
	}
	
	subTree[pos] = ans;
	return ans;
	
}

void solve() {
	int N, Q; 
	cin >> N >> Q;
	values.resize(N);
	tree.resize(N);
	for(auto  &t: values)
		cin >> t;
	forn(i, N-1){
		int a,b; cin >> a >> b;
		a--; b--;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	vector<pair<int,int>> queries(Q);
	for(auto &q: queries)
		cin >> q.first >> q.second;
	vector<vector<ll>> subTree(N);
	dfs(0, -1, subTree);
	debug(subTree);
	for(auto &q: queries){
		int n = len(subTree[q.first-1]) -1;
		int po = q.second -1;
		cout << subTree[q.first-1][n-po] << nl;
	}
		
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	solve();

	return 0;
}
