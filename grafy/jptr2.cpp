#include <bits/stdc++.h>
using namespace std;   // Mateusz Dziewulski
typedef long long LL;  // XIII LO Szczecin
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
#define st first
#define nd second
#define pb push_back
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.st << ", " << p.nd << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#define LOG(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'

const int maxn = 2 * 1e5;
int n;

void make_jump(int u, int p,int d, vector<int>& depth, vector<int>& jump, vector<vector<int>>& adj){
	depth[u] = d;

	if(depth[p] - depth[jump[p]] == depth[jump[p]] - depth[jump[jump[p]]]){
		jump[u] = jump[jump[p]];
	}else{
		jump[u] = p;
	}

	for(int i : adj[u]){
		if(i!=p)
		make_jump(i, u, d+1, depth, jump, adj);
	}
}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> n;

 	vector<vector<int>> adj(n - 1);

 	REP(i, n-1){
 		int a, b;
 		cin >> a >> b;
 		a--;b--;

 		adj[b].pb(a);
 		adj[a].pb(b);
 	}

 	vector<int> depth(n);
 	vector<int> jump(n);

 	jump[0] = 0;
 	make_jump(0, 0,0, depth, jump, adj);
}