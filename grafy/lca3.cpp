#include<bits/stdc++.h>
#include"../struktury-danych/rmq.cpp"
using namespace std;
// LCA w O(1)

struct LCA_query{
	struct Node{
		int label, depth;

		bool operator<(Node& other){
			return depth < other.depth;
		}

		Node(int a, int b) : label(a), depth(b){}
	};

	vector<Node> euler;
	RMQ<Node> helper;
	vector<vector<int>> adj;
	int n;
	vector<int> st;

	void dfs(int u, int p, int d){
		st[u] = sz(euler);
		for(int v : adj[u]){
			if(v == p) 
				continue;
			euler.emplace_back(u, d);
			dfs(v, u, d+1);
		}
		euler.emplace_back(u, d);
	}

	int lca(int a, int b){
		if(st[a] > st[b]) swap(a, b);
		return helper.query(st[a], st[b]).label;
	}

	LCA_query(vector<vector<int>>& v, int root = 0) : adj(v), n(sz(v)), st(vector<int>(n)){
		dfs(root, root, 0);
		helper = RMQ(euler);
	}
};