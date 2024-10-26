#include<bits/stdc++.h>
using namespace std;

vector<int> path_end;
vector<int> subtree_size;
vector<int> preorder; // przydaje się np z drzewami przedziałowymi

int dfs(int u, int p, vector<vector<int>>& adj){
	for(int i : adj[u])
		if(i != p){
			subtree_size[u] += dfs(i, u, adj);
		}
	return ++subtree_size[u];
}

void hld(int u, int p, vector<vector<int>>& adj, int& time){
	preorder[u] = time;
	time++;

	int maxsize = 0;
	int heavy = u;

	for(int i : adj[u]) // znajdź ciężką krawędź
		if(i != p && subtree_size[i] > maxsize){
			maxsize = subtree_size[i];
			heavy = i;
		}

	path_end[heavy] = path_end[u];
	if(heavy != u) // żeby się nie zapetlać
		hld(heavy, u, adj, time);

	for(int i : adj[u])
		if(i != p && i != heavy){
			path_end[i] = i;
			hld(i, u, adj, time);
		}
}

int main(){
	int n;
	cin >> n;

	path_end = vector<int>(n, 0);
	preorder = vector<int>(n);
	subtree_size = vector<int>(n, 0);

	vector<vector<int>> adj(n);

	for(int i = 0;i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	dfs(0, 0, adj);
	int time = 0;
	hld(0, 0, adj, time);
}