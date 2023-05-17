#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;

#define ll long long
#define fn(i,n) for(ll i=0;i<n;i++)

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> l(n,0);
        fn(i,n) cin>>l[i];
        vector <ll> b(n,0);
        fn(i,n){
            while(l[i]!=0){
                b.push_back(l[i]);
                l[i]=l[i]>>1;
            }

        }
        debug(b);
        sort(b.begin(),b.end());
        ll q;
        cin>>q;
        while(q--){
            ll k;
            cin>>k;
            auto low=lower_bound(b.begin(),b.end(),k);
            cout << *low << endl;
            cout<<b[low-b.begin()-1]<<endl;
        }
    }

    return 0;
}