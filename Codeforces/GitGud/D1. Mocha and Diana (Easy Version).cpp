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


bool hasCycle(int me, int parent, vector<bool> &visited, vector<vector<int>> &graph){
	if(visited[me])
		return true;
	
	visited[me] = true;
	bool ans = false;
	
	for(int i = 0; i < len(graph[0]); ++i){
		if(graph[me][i] == 1 and i != parent){
			ans |= hasCycle(i, me, visited, graph);
		}
			
	}
	
	return ans;

}


void solve() {
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<vector<int>> mocha(n, vector<int>(n, -1));
	vector<vector<int>> diana(n, vector<int>(n, -1));
	forn(i, m1){
		int a, b; cin >> a >>b;
		a-=1; b-=1;
		mocha[a][b] = 1;
		mocha[b][a] = 1;
	}	
	forn(i, m2){
		int a, b; cin >> a >>b;
		a-=1; b-=1;
		diana[a][b] = 1;
		diana[b][a] = 1;
	}
	
	vector<pair<int,int>> ans;
	forn(i, n)
		forn(j, n){
			if(j != i and mocha[i][j] == -1 and diana[i][j] == -1){
				vector<bool> visitedm(n);
				vector<bool> visitedd(n);

				mocha[i][j] = 1; mocha[j][i] = 1;
				diana[i][j] = 1; diana[j][i] = 1;
				if (hasCycle(i,-1, visitedm, mocha) or 
				    hasCycle(i, -1, visitedd, diana) ){
					mocha[i][j] = INT_MAX; mocha[j][i] = INT_MAX;
					diana[i][j] = INT_MAX; diana[j][i] = INT_MAX;
				} else {
					ans.push_back({i,j});
				}
			}
		}						
	
	
	cout << ans.size() << endl;
	for(auto c: ans)
		cout << c.first+1 << " " << c.second+1 << endl;
	

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	
		solve();

	return 0;
}
