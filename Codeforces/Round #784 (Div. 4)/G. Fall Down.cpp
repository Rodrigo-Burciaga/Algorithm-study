#include <iostream>
#include <bits/stdc++.h>

using namespace std;



void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for(auto &row:grid)
		for(auto &col: row)
			cin >> col;
			
	for(int i = 0; i<m; i++){
		int space = -1;
		for(int j=n-1; j>=0; j--) {
			if(grid[j][i] == '.' and space == -1) space = j;
			
			if(grid[j][i] == '*' and space != -1){
				swap(grid[j][i], grid[space][i]);
				j = space;
				space = -1;
			} 
			
			if(grid[j][i] == 'o') space = -1;
			
			
		}
	}
	
	
	for(auto &row:grid){
		for(auto &col: row)
			cout << col;
		cout << endl;
	}
	
	cout << endl;
		
}

int main(){
	int T; cin >> T;
	while(T--)
		solve();
}