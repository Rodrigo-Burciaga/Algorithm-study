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



using namespace std;

void solve(int caseNo) {
	int rows, cols; cin >> rows >> cols;
	vector<vector<char>> grid(rows, vector<char>(cols));
	int trees = 0;
	for(auto &row: grid)
		for(auto &col: row){
			cin >> col;
			if(col == '^') trees++;
		}
			
	if( (rows == 1 or cols == 1) and trees > 0){
		cout << "Case #"<< caseNo << ": Impossible" << endl;
		return;
	} 
	
	
	cout << "Case #"<< caseNo << ": Possible" << endl;
	if( rows == 1 or cols == 1){
		for(auto &row: grid){
			for(auto &col: row)
				cout << col;
			cout << endl;
		}
		return;
	}
	
	
	for(auto &row: grid){
		for(auto &col: row)
			cout << "^";
		cout << endl;
	}
	
	
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	int num = 1;
	while(T--)
		solve(num++);

	return 0;
}
