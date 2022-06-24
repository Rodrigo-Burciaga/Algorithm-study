#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//longest common subsequence implementation
int lcs(string &a, string &b, int n, int m, int *memo){
	
	if( (n >= (int) a.size()) or (m >= (int)b.size()) )
		return 0;
	
	if(memo[n*b.size()+m] != -1) return memo[n*b.size()+m];
	
	if(a[n] == b[m]){
	    return memo[n*b.size()+m] = 1 + lcs(a, b, n+1, m+1, memo);
	}
	
	return memo[n*b.size()+m] = max(lcs(a, b, n+1, m, memo), lcs(a, b, n, m+1, memo));

}


int main(){
	string a, b; cin >> a >> b;
	int n = a.size();
	int m = b.size();
	int memo[n+1][m+1];
	memset(memo,-1, sizeof(memo));
	cout << lcs(a,b,0,0, (int *) memo);
	return 0;
}