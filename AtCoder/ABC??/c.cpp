#include <bits/stdc++.h>
#include <sys/resource.h>

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
#define __  ios::sync_with_stdio(0), cin.tie(0);


#define MOD  998244353
const char nl = '\n';
const ll INF = 1e18;




using namespace std;

int dp[10][1048576] = {0};

int solve(int num, int digits) {
		
	if(dp[num][digits] != 0) return dp[num][digits];
	
	for(int i = max(num -1 , 1); i <= min(num+1, 9); i++){
		dp[num][digits] += solve(i, digits-1);
		dp[num][digits] %= MOD;
	}

	
	return dp[num][digits];
}

int main() {

	__
	
	const rlim_t kStackSize = 250 * 1024 * 1024;   // min stack size = 16 MB
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
	
	forn(i, 10)
		dp[i][0] = 1;
	
	int n; cin >> n;
	
	int sol = 0;
	forr(i, 1, 9){
		sol += solve(i, n-1);
		sol %= MOD;
	}

	
	sol %= MOD;
	cout << sol << endl;


	return 0;
}
