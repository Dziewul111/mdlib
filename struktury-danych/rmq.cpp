#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define REP(i, n) for(int i = 0; i < n; i++)
#define min(a, b) (a < b) ? a : b

template<typename T>
struct RMQ{
	vector<vector<T>> st;

	RMQ(vector<T>& v){
		int n = sz(v), lg = 0;
		while((1<<lg) < n) lg++;
		st.resize(lg+1, v);
		for(int i = 1; i <= lg; i++)
			for(int j = 0; j < n; j++){
				st[i][j] = st[i-1][j];
				int q = j + (1 << (i-1));
				if(q < n) st[i][j] = min(st[i][j], st[i-1][q]);
			}		
	}

	RMQ(){}

	T query(int l, int r){
		int q = __lg(r-l+1), x = r - (1<<q) + 1;;
		return min(st[q][l], st[q][x]);
	}
};