#include <bits/stdc++.h>
using namespace std;   // Mateusz Dziewulski
#define pb push_back
#define REP(i, n) for(int i = 0; i < (n); i++)
int n;

int go_up(int a, int d, vector<int>& jump, vector<int>& depth, vector<int>& parent){
	int x = depth[a] - d;

	while(depth[a] > x){
		if(depth[jump[a]] >= x)
			a = jump[a];
		else
			a = parent[a];
	}

	return a;
}

void make_jump(int u, int p,int d, vector<int>& depth, vector<int>& jump, vector<vector<int>>& adj){
	depth[u] = d;

	if(depth[p] - depth[jump[p]] == depth[jump[p]] - depth[jump[jump[p]]]){
		jump[u] = jump[jump[p]];
	}else{
		jump[u] = p;
	}

	for(int i : adj[u]){
		if(i!=p)
		make_jump(i, u, d+1, depth, jump, adj);
	}
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

 	vector<vector<int>> adj(n - 1);

 	REP(i, n-1){
 		int a, b;
 		cin >> a >> b;
 		a--;b--;

 		adj[b].pb(a);
 		adj[a].pb(b);
 	}

 	vector<int> depth(n);
 	vector<int> jump(n);
 	vector<int> parent(n);

 	jump[0] = 0;
 	make_jump(0, 0,0, depth, jump, adj);
}
