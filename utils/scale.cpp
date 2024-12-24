#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define sz(x) (int)x.size()

// jakoś O(n log n)
void skaluj(vector<int>& xd){
	set<pair<int, int>> s;

	int idx = 0;
	REP(i, sz(xd)) s.insert({xd[i], i});
	int prev = s.begin()->first;
	for(auto [x, i] : s){
		if(x != prev) idx++;
		xd[i] = idx;
		prev = x;
	}
}
