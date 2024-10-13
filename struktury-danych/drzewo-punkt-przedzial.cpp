#include<bits/stdc++.h>
using namespace std;

// drzewo punkt-przedział typu [+, Σ]

struct punkt_przedzial{

	int base;
	vector<int> tree;

	punkt_przedzial(int n){
		base = 1 << (int)ceil(log2(n));

		tree.resize(2 * base, 0);
	}

	void add(int a, int x){
		a += base;

		while(a > 0){
			tree[a] += x;
			a /= 2;
		}
	}

	int query(int l, int r, int node, int node_left, int node_right){

		if(node_left >= l && node_right <= r){
			return tree[node];
		}

		int sum = 0;
		int mid = (node_left + node_right)/2;
		
		if(l <= mid)
			sum += query(l, r, 2*node, node_left, mid);

		if(r >= mid+1)
			sum += query(l, r, 2*node + 1, mid+1, node_right);


		return sum;
	}

	int query(int l, int r){
		return query(l, r, 1, 0, base-1);
	}
};
