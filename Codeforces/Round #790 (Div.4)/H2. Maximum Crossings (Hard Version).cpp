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

template<typename T>
struct FenwickTree{
	vector<T> bit;
	FenwickTree(int N) : bit(N+1, 0) {}
	
	void add(int index, T value){
		while(index < (T)bit.size()){
			bit[index] += value;
			index += (index&-index);
		}
	}
	
	T sum(int index){
		T ans = 0;
		while(index > 0){
			ans += bit[index];
			index -= (index&-index);
		}
		
		return ans;
		
	}
};

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	for(auto &c: arr)
		cin >> c;
		
	FenwickTree<int> ft(n);
	ll ans = 0;
	for(int i= n-1; i >= 0; i--){
		ans += ft.sum(arr[i]);
		
		ft.add(arr[i], 1);
	}
	
	cout << ans << endl;
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while(T--)
		solve();

	return 0;
}
