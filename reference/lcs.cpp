#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &memo){
	if(n >= (int)a.size() or m >= (int)b.size())
		return 0;
	
	if(memo[n][m] != -1) return memo[n][m];
	
	if(a[n] == b[m])
		return memo[n][m] = 1 + lcs(a, b, n+1, m+1, memo);
	
	return memo[n][m] = max(lcs(a, b, n, m+1, memo), lcs(a, b, n+1, m, memo));
}

int main(){
	
	string a, b; cin >> a;
	cin >> b;
	vector<vector<int>> memo(a.size(), vector<int>(b.size(), -1));
	cout << lcs(a, b, 0, 0, memo);
	
	return 0;
}