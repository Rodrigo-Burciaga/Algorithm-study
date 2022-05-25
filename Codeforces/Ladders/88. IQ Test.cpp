#include <iostream>
#include <bits/stdc++.h>

#define __ ios::sync_with_stdio(0), cin.tie(0);

using namespace std;

void solve(){
	vector<vector<char>> grid(4, vector<char>(4));
	for(auto &row: grid)
		for(auto &col: row)
			cin >> col;
		
	for(int row = 0; row<3; ++row){
		for(int col = 0; col<3; ++col){
			unordered_map<char, int> freq;
			freq[grid[row][col]]++;
			freq[grid[row][col+1]]++;
			freq[grid[row+1][col]]++;
			freq[grid[row+1][col+1]]++;
			
			if(freq['#'] >= 3 or freq['.'] >= 3){
				cout << "YES" << endl;
				return;
			}
		}
	}	
	
	
	
	cout << "NO" << endl;
	
}

int main(){
	__
	
	solve();
}