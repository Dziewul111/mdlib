#include<bits/stdc++.h>
using namespace std;

struct przedzial_przedzial{


	int base;
	vector<int> tree;
	vector<int> lazy;

	przedzial_przedzial(int n){
		base = ceil(log2(n));

		tree.resize(1<<base);
		lazy.resize(1<<base);
	}	

	void update(int l, int r, int x){

	}


	
}