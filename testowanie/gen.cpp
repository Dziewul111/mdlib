#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define st first
#define nd second
#define ITF(e, v) for(auto& e : (v))
typedef pair<int, int> pii;
typedef long long LL;

const int maxn = 1e3;
const int maxq = 1e3;

mt19937 rng;
int rd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

LL rdll(LL l, LL r){
	return uniform_int_distribution<LL>(l, r)(rng);
}

vector<pair<int, int>> gen_tree(int n) {
	vector<int> code(n - 2), deg(n + 1);
	ITF (x, code) x = rd(1, n), deg[x]++;
	int ptr = 1, leaf = 1;
	while (deg[ptr]) ++ptr, ++leaf;
	vector<pair<int, int>> edges;
	ITF (p, code) {
		edges.emplace_back(leaf, p);
		if (--deg[p] == 0 && p < ptr)
			leaf = p;
		else {
			do ptr++;
			while (deg[ptr]);
			leaf = ptr;
		}
	}
	edges.emplace_back(leaf, n);
	return edges;
}


int main(int argc, char* argv[]){  
    cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    int seed = atoi(argv[1]);
    rng = mt19937(seed);
}	