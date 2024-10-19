#include<bits/stdc++.h>
using namespace std;
/*

Union find 

dla elementów ∈ [0, n)

*/



struct union_find{
	vector<int> link;
	vector<int> size;

	uinon_find(int n){
		link.resize(n);
		size.resize(n, 1);

		for(int i = 0; i < n; i++)
			link[i] = i;
	}

	int root(int x){
		if(link[x] == x)
			return x;
		return link[x] = root(link[x]);
	}

	bool find(int a, int b){
		return root(a) == root(b);
	}

	void unite(int a, int b){
		a = root(a);
		b = root(b);

		if(a != b){
			if(size[a] < size[b])
				swap(a, b);

			link[b] = a;
			size[a] += size[b];
		}
	}
};
