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

void dfs(vector<vector<int>> &path,int root, vector<int> &temp_path,
			vector<vector<int>> &graph){
	
	if(graph[root].empty()){
		path.push_back(temp_path);
		return;
	}
	
	for(auto node: graph[root]){
		temp_path.push_back(node);
		dfs(path, node, temp_path, graph);
		temp_path.clear();
	}
	
}
 
 
void solve(){
	int n; cin>>n;
	vector<vector<int>> graph(n+1);
	int root;
	for(int i=1; i<=n; i++){
		int parent; cin >> parent;
		if(i==parent){
			root = i;
			continue;	
		}
		graph[parent].push_back(i);
	}
	
	vector<vector<int>> path;
	vector<int> temp = {root};
	dfs(path, root, temp, graph);
	cout << path.size() << endl;
	for(auto st: path){
		cout << st.size() << endl;
		for(auto n: st)
			cout << n << " ";
		cout << endl;
	}
	
	cout << endl;
	
}
 

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
