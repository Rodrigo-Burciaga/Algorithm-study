#include <iostream>
#include <vector>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
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


vector<bool> sieve(int n){
    vector<bool> is(n+1, true); // arreglo de marcas inicializado en true, es decir, todos los números son "primos" al inicio
    is[0] = is[1] = false;      // excepto el 0 y el 1
    for(int i = 4; i <= n; i += 2){
        is[i] = false; // marcamos todos los múltiplos mayores de 2 como compuestos
    }
    for(int i = 3; i*i <= n; i += 2){ // comenzamos a iterar por los impares desde el 3
        if(is[i]){ // si el número actual es primo, marcamos todos sus múltiplos mayores
            for(int j = i*i; j <= n; j += 2*i){ // comenzamos en i*i y solo iteramos por los impares
                is[j] = false;
            }
        }
    }
    return is;
}

void solve() {
	vector<bool> criba = sieve(210);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	forr(i, a, b){
		bool canPrime = false;
		forr(j, c, d){
			canPrime = canPrime || criba[i+j];
		}
		
		if(!canPrime){
			cout << "Takahashi" << nl;
			return;
		}
	}
	
	cout << "Aoki" << nl;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


		solve();

	return 0;
}
