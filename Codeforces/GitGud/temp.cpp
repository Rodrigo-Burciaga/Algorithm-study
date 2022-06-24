#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
     using namespace std;
    
    #define rep(i,l,r)for(int i=(l);i<(r);i++)
    
    struct DSU{
	
	vector<int> parent;
	vector<int> sz;
	
	DSU(int n): parent(n), sz(n,1) {
		for(int i = 0; i<n; ++i)
			parent[i] = i;
	}
	
	int find(int u){
		return parent[u] = (parent[u] == u ? u : find(parent[u]));
	}
	
	void union_find(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if(pu != pv) {
			if(sz[pu] < sz[pv])
			swap(pu, pv);
			sz[pu] += sz[pv];
			parent[pv] = pu;	
		}
	}
	
	void print(){
		for(int i = 0; i< (int)parent.size(); i++){
			cout << "parent[" << i << "]= " << parent[i] << endl; 
		}
	}
	
	
	bool same_set(int a, int b){
		return parent[a] == parent[b];
	}
	
};

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif







     
    int main(){
    	int n,m;
    	cin >> n >> m;
    	vector<int>d(n);
    	rep(i,0,n)cin >> d[i];
     
    	DSU dsu(n);
    	rep(i,0,m){
    		int x,y;
    		cin >> x >> y;
    		x--,y--;
    		d[x]--,d[y]--;
    		dsu.union_find(x,y);
    	}
     
    	vector<vector<int>>temp(n);
    	rep(i,0,n){
    		if(d[i]<0){
    			cout << -1;
    			return 0;
    		}
    		rep(_,0,d[i])temp[dsu.find(i)].push_back(i);
    	}
    	
    	debug(temp);
    	
    	vector<vector<int>>c2;
    	vector<int>c1;
    	rep(i,0,n){
    		if(temp[i].size()==1)c1.push_back(temp[i][0]);
    		else if(temp[i].size()>1) c2.push_back(temp[i]);
    	}
    	
    	
    	vector<pair<int,int>>ans;
    	for(auto v:c2){
    		for(int i=0;i<(int)v.size()-1;i++){
    			if(c1.empty()){
    				cout << -1;
    				return 0;
    			}
    			dsu.union_find(v[i],c1.back());
    			ans.push_back({v[i],c1.back()});
    			c1.pop_back();
    		}
    		c1.push_back(v.back());
    	}
    	
    	
    	if(c1.size()!=2){
    		cout << -1;
    		return 0;
    	}
    	
    	dsu.union_find(c1[0],c1[1]);
    	ans.push_back({c1[0],c1[1]});
    	
    	int maxi = 0;
    	for(auto c: dsu.sz)
    		maxi =  max(maxi, c);  
    		  	
    	if(maxi!=n){
    		cout << -1;
    		return 0;
    	}
    	
    	for(auto[p,q]:ans){
    		cout << p+1 << ' ' << q+1 << endl;
    	}
    }