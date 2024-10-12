#include<bits/stdc++.h>
using namespace std;
#define pb push_back

/*
* zwykłe jump pointery
* 
* całkiem przyjemne
*
* czas : prepocess O(n log n) query O(log n)
*
*/

void dfs(int u, int p, int d, vector<int>& parent, vector<int>& depth, vector<vector<int>>& adj){
	parent[u] = p;
	depth[u] = d;

	for(int i : adj[u])
		if(i != p)
			dfs(i, u, d+1, parent, depth, adj);
}

int main(){
	int n;
	cin >> n;

	int l = ceil(log2(n));

	vector<vector<int>> adj(n);

	for(int i = 0; i < n-1; i ++){
		int a, b;
		cin >> a >> b;
		a--;b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	int root = 0; // działa dla dowolnego wierchołka

	vector<vector<int>> jump(n, vector<int>(l+1));
	vector<int> parent(n);
	vector<int> depth(n);

	parent[root] = root;

	dfs(root, root, 0, parent, depth, adj);

	for(int i = 0; i < n; i++)
		jump[i][0] = parent[i];

	for(int i = 1; i <= l; i++){
		for(int j = 0; j < n; j++){
			jump[j][i] = jump[jump[j][i-1]][i-1];
		}
	}

	for(auto i : jump){
		for(auto j : i){
			cout << j+1 << ' ';
		}
		cout << '\n';
	}
}