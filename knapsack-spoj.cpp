#include <bits/stdc++.h>

/**
	https://www.spoj.com/problems/KNAPSACK/
*/

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

ll dp(int index, int capacity, vector<vector<ll>> &memo, vector<int> &profits, 
		vector<int> &weights){
	
	if(index < 0 or capacity == 0) return 0;
	
	if(memo[index][capacity] != -1) return memo[index][capacity];
	
		
	ll taken = 0;
	if(weights[index]<=capacity)
		 taken = profits[index] + dp(index-1, capacity - weights[index], memo, 
									   profits, weights);
	
	ll not_taken = dp(index-1, capacity, memo, profits, weights);
	
	return memo[index][capacity] =  max(not_taken, taken);
	
}


void solve() {
	int c, n;
	cin >> c >> n;
	vector<int> weights(n);
	vector<int> profits(n);
	forn(i, n){
		cin >> weights[i];
		cin >> profits[i];
	}
	
	vector<vector<ll>> memo(n, vector<ll>(c+10, -1));
	cout << dp(n-1, c, memo, profits, weights) << endl;
	
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}












