#include<bits/stdc++.h>

int LCA(int a, int b, vector<int>& jump, vector<int>& depth, vector<int>& parent){

	if(depth[a] < depth[b])
		return LCA(b, a, jump, depth, parent);

	// podnosimy do tej samej wysokosci
	while(depth[a] > depth[b]){
		if(depth[jump[a]] >= depth[b])
			a = jump[a];
		else
			a = parent[a];
	}

	while(a != b){
		if(jump[a] != jump[b]){
			a = jump[a];
			b = jump[b];
		}else{
			a = parent[a];
			b = parent[b];
		}
	}
	return a;
}
