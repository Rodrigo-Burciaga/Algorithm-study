#include <bits/stdc++.h>
#define ll long long
#define __  ios::sync_with_stdio(0), cin.tie(0);

/** 
	https://codeforces.com/problemset/problem/295/A/
**/

using namespace std;

template<typename T>
struct FenwickTree{
	vector<T> bit;
	FenwickTree(int N) : bit(N+1, 0) {}
	
	void add(int index, T value){
		while(index < (int)bit.size()){
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

	void range_add(int l, int r, T val) {
	    add(l, val);
	    add(r + 1, -val);
	}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	FenwickTree<ll> ft(n);
	vector<int> arr(n+1);
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
		
	int queries[m+1][3];
	for(int i = 1; i <= m; i++)
		cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
	

	FenwickTree<ll> consultas(m);
	while(k--){
		ll x, y; cin >> x >> y;
		consultas.range_add(x,y, 1);
	}
	
	for(int i = 1; i <= m; i++){
		ll num = consultas.sum(i);
		ft.range_add(queries[i][0], queries[i][1], queries[i][2]*num);
	}
	
	for(int i = 1; i <= n; i++)
		cout << ft.sum(i) + arr[i] << " ";
	
}

int main(){
	__
	solve();
	return 0;
}