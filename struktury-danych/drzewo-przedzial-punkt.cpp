#include<bits/stdc++.h>
using namespace std;

// drzewo przedział-punkt typu +

struct przedzial_punkt{
	int base;
	vector<int> tree;


	przedzial_punkt(int n){
		base = 1 << (int)ceil(log2(n));

		tree.resize(2*base, 0);
	}

	void add(int l , int r, int node, int node_left, int node_right, int x){
		if(node_left >= l && node_right <= r){
			tree[node] += x;
			return;
		}

		int mid = (node_left + node_right) / 2;

		if(l <= mid)
			add(l, r, 2*node, node_left, mid, x);

		if(r >= mid+1)
			add(l, r, 2*node + 1, mid+1, node_right, x);
	}

	void add(int l, int r, int x){
		add(l, r, 1, 0, base-1, x);
	}

	int query(int i){
		i += base;
		int ret = 0;

		while(i > 0){
			ret += tree[i];
			i >>= 1;
		}

		return ret;
	}
};