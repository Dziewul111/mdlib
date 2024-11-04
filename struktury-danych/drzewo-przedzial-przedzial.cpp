#include<bits/stdc++.h>
using namespace std;
// drzewo przedzial przedzial z lazy propagation do dawanania na przedziale 
// i brania maxa z przedzialu

struct drzewo{
	vector<int> tree;
	vector<int> lazy;
	int base = 1;

	drzewo(int n){
		base = 1<<int(ceil(log2(n)));
		tree = vector<int>(2*base, 0);
		lazy = vector<int>(2*base, 0);
	}

	void push(int node){
		if(node >= base) return;
		tree[2*node] += lazy[node];
		tree[2*node + 1] += lazy[node];
		lazy[2 * node] += lazy[node];
		lazy[2*node + 1] += lazy[node];
		lazy[node] = 0;
	}

	int query(int node, int node_left, int node_right, int l, int r){
		if(l <= node_left && node_right <= r)
			return tree[node];

		push(node);

		int mid = (node_left + node_right)/2;
		int ans = INT_MIN;
		if(l <= mid)
			ans = max(ans, query(2*node, node_left, mid, l, r));
		if(r >= mid+1)
			ans = max(ans, query(2*node + 1, mid+1, node_right, l, r));

		return ans;
	}

	int query(int l, int r){
		return query(1, 0, base-1, l, r);
	}

	void update(int node, int node_left, int node_right, int l, int r, int x){
		if(l <= node_left && node_right <= r){
			tree[node] += x;
			lazy[node] += x;
			return;
 		}
 		push(node);

 		int mid = (node_left + node_right)/2;

 		if(l <= mid)
 			update(2*node, node_left, mid, l, r, x);
 		if(r > mid)
 			update(2*node + 1, mid+1, node_right, l, r, x);

 		tree[node] = max(tree[2*node], tree[2*node + 1]);
	}

	void update(int l, int r, int x){
		update(1, 0, base-1, l, r, x);
	}
};
