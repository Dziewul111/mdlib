#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sz(x) (int)x.size()

// algorytm tarjan
// zwraca ładnego DAGa silnie spójnych składowych 

vector<bool> odw;
void dfs(int u, vector<vector<int>>& adj, vector<int>& out){
	odw[u] = 1;

	for(int i : adj[u])
		if(!odw[i])
			dfs(i, adj, out);
	out.pb(u);
}

int n, m;
vector<vector<int>> tarjan(vector<vector<int>>& adj){
	vector<vector<int>> rev(n);
	vector<int> post;
	odw = vector<bool>(n, 0);

	REP(i, n)
		for(int j : adj[i])
			rev[j].pb(i);

	REP(i, n)
		if(!odw[i])
			dfs(i, adj, post);

	reverse(post.begin(), post.end());
	odw = vector<bool>(n, 0);
	int id = 0;
	vector<int> rep(n);
	for(int i : post){
		if(odw[i]) continue;
		vector<int> c;
		dfs(i, rev, c);
		for(int j : c) rep[j] = id;
		id++;
	}
	vector<vector<int>> dag(id);

	REP(u, n)
		for(int v : adj[u])
			if(rep[u] != rep[v])
				dag[rep[u]].pb(rep[v]);
	return dag;
}