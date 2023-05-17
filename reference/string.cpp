#include <bits/stdc++.h>
 
#define endl '\n'
#define lli long long int
#define ld long double
#define forn(i,n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define SZ(s) int(s.size())

using namespace std;

typedef vector<lli> VLL;
typedef vector<int> VI;


struct KMP{
		
	vector<int> getPi(string s){
	    int n = s.length();
	    vector<int> pi(n);
	    pi[0] = 0;
	
	    for(int i = 1; i < n; i++) {
	        int j = pi[i-1];
	        while(j > 0 && s[i] != s[ j ] ) j = pi[j-1]; // SUM O(n)
	
	        if(s[i] == s[j]) pi[i] = j + 1;
	        else pi[i] = 0;
	        
	    }
	
	    return pi;
	}
	
};


int main () {    
    string cadena; cin>>cadena;

    KMP k;

	auto pi = k.getPi(cadena);

    for(auto x: pi) cout << x << " ";


	return 0;
}