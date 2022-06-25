#include <bits/stdc++.h>

using namespace std;


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
	
	bool sameSet(int a, int b){
		return find(a) == find(b);
	}
	
};

int main(){
	
	return 0;
}