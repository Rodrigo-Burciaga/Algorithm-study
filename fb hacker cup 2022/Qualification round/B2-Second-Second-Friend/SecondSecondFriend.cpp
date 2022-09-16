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
#include <sys/resource.h>

						  //  right   left     up     down  
vector<pair<int,int>> moves = {{0,1},{0,-1}, {-1,0}, {1,0}};
int rows, cols;
vector<vector<char>> grid, cp;
struct Node {
   int values[4] = {-1,-1,-1,-1};
};



bool validPosition(pair<int,int> position){
	if(position.first < 0 or position.first >= rows) return false;
	
	if(position.second < 0 or position.second >= cols) return false;
	
	
	return (grid[position.first][position.second] == '^' or
			 grid[position.first][position.second] == '.');
}

bool hasCycle(pair<int,int> parent, pair<int,int> me, vector<vector<bool>> &visited, 
			map<int, map<int, Node>> &memo){
		
	if(visited[me.first][me.second]) return true;
		
	visited[me.first][me.second] = true;
	cp[me.first][me.second] = '^';
	

	forn(i, 4)
    	if(memo[me.first][me.second].values[i] == 1)return true; 
    	
    
    
	bool ans =  false;	
	int pos = 0;
	
	for(auto &move: moves){
		pair<int,int> possible = {move.first + me.first, move.second + me.second};
		if(!validPosition(possible)) {
			pos++;
			continue;
		}
		if(possible != parent){
			ans |= (memo[me.first][me.second].values[pos] != -1) ?
								memo[me.first][me.second].values[pos]: 
					memo[me.first][me.second].values[pos] = hasCycle(me, possible, visited, memo);
			if(ans) return ans;
		}
		pos++;
	}
	
    cp[me.first][me.second] = '.'; 
	
	return ans;
	
}


int numberCycles(pair<int,int> me, map<int, map<int, Node>> &memo){
	
	int ans = 0;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	visited[me.first][me.second] = true; 
	int pos= 0;
	for(auto &move: moves){
		pair<int,int> possible = {move.first + me.first, move.second + me.second};
		if(!validPosition(possible)) {
		
			pos++;
			continue;
		}
		ans += (memo[me.first][me.second].values[pos] != -1) ?
					memo[me.first][me.second].values[pos]: 
					memo[me.first][me.second].values[pos] = hasCycle(me, possible, visited, memo);
		if(ans == 2) return 2;
		pos++;

	}
	return ans;
}



void solve(int caseNo) {
	cin >> rows >> cols;
	grid.erase(grid.begin(), grid.end());
	cp.erase(cp.begin(), cp.end());
	grid.resize(rows, vector<char>(cols));
	cp.resize(rows, vector<char>(cols));
	map<int, map<int, Node>> memo;
	int trees = 0;
	for(auto &row: grid)
		for(auto &col: row){
			cin >> col;
			if(col == '^') trees++;
		}
	
	cp = grid;
	if( (rows == 1 or cols == 1) and trees > 0){
		cout << "Case #"<< caseNo << ": Impossible" << endl;
		return;
	} 
	
	
	if( rows == 1 or cols == 1 or trees == 0){
		cout << "Case #"<< caseNo << ": Possible" << endl;
		for(auto &row: grid){
			for(auto &col: row)
				cout << col;
			cout << endl;
		}
		return;
	}
	
	
	for(int i = 0; i< rows; i++)
		for(int j = 0; j < cols; j++){
			if(grid[i][j] == '^'){
				int num = numberCycles({i,j}, memo);
				if(num < 2) {
					cout << "Case #"<< caseNo << ": Impossible" << endl;
					return;
				}
			}
		}
	
	
	
	
	cout << "Case #"<< caseNo << ": Possible" << endl;
	for(auto &row: cp){
		for(auto &col: row)
			cout << col;
		cout << endl;
	}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	const rlim_t kStackSize = 1024 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
	

	int T; cin >> T;
	int num = 1;
	while(T--)
		solve(num++);

	return 0;
}
