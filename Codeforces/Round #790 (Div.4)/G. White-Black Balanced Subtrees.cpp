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

int counter;

pair<int, int> dfs(vector<vector<int>> &graph, int root, string &colors){
	
	pair<int,int> ans = { colors[root-1] == 'W', colors[root-1] == 'B'};
	
	for(auto node: graph[root]){
		pair<int,int> temp = dfs(graph, node, colors);
		ans.first += temp.first;
		ans.second += temp.second;
	}
		
	if(ans.se == ans.fi) counter++;
	
	return ans;
}

void solve() {
	counter = 0;
	int n; cin >> n;
	vector<vector<int>> graph(n+1);
	for(int i = 2; i<= n; ++i){
		int pa; cin >> pa;
		graph[pa].pb(i);
	}
	string colors; cin >> colors;
	dfs(graph, 1, colors);
	cout << counter << endl;
	
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
