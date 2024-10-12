#include<bits/stdc++.h>
using namespace std;
#define ssize(x) x.size()

// LCA w O(log n) z binary lifting

int lca(int a, int b, vector<int>& depth, vector<vector<int>>& jump){
	if(depth[a] < depth[b])
		swap(a, b);

	int l = ssize(jump[0]) - 1;

	//sprowadzamy wierchołki do tej samej glębokości
	for(int i = l; i >= 0 && depth[a] > depth[b]; i--){
		if(depth[jump[a][i]] >= depth[b])
			a = jump[a][i];
	}

	if(a == b)
		return a;

	for(int i = l; i >= 0; i--){
		if(jump[a][i] != jump[b][i]){
			a = jump[a][i];
			b = jump[b][i];
		}
	}

	return jump[a][0];
}
