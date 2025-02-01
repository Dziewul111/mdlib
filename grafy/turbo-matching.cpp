#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n);i++)
#define pb push_back
#define sz(x) (int)x.size()

struct Matching{	
	int n, m;
	vector<int> match;
	vector<bool> used;
	vector<vector<int>> l, r;
	bool perfect = 1;
	int count = 0;

	bool turbo_match(int u){
		if(used[u])
			return 0;
		used[u] = 1;
		for(int i : r[u]){
			if(match[i] == -1 || turbo_match(match[i])){
				match[i] = u;
				return 1;
			}
		}
		return 0;	
	}


	Matching(vector<vector<int>>& a, vector<vector<int>>& b) : n(sz(a)), l(a), r(b){
		match = vector<int>(n, -1);
		
		REP(i, n){
			used = vector<bool>(n, 0);
			count += turbo_match(i);
		}
		perfect = (count == n);
	}	
};