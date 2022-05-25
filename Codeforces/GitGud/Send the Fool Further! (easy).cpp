#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

#define ll long long


ll ans = 0;


void dfs(int me, ll cost, vector<bool> &visited, vector<vector<int>> &graph){
	visited[me] = true;
	ans = max(ans, cost);
	
	for(int node = 0; node < (int)graph[me].size(); node++){
		if(graph[me][node] != -1 and !visited[node]){
			dfs(node, cost+graph[me][node], visited, graph);
		}
	}	
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, -1));
	for(int i = 0; i<n; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
		graph[v][u] = c;
	}
	
	vector<bool> visited(n, false);
	
	
	dfs(0, 0, visited, graph);
	cout << ans << endl;
	
}

int main(){
	__
	solve();
	return 0;
}