#include<bits/stdc++.h>
using namespace std;
#define fast() cin.tie(0)->sync_with_stdio(0)
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ALL(x) x.begin(), x.end()
#define ITF(e, c) for(auto& e : (c))
#define pb push_back

// D- query

vector<int> v;
vector<int> cnt;
int ile = 0;
int n;
int c;

void rem(int i){
	cnt[v[i]]--;
	if(!cnt[v[i]]) ile--;
}

void add(int i){
	if(!cnt[v[i]]) ile++;
	cnt[v[i]]++;
}

struct query{
	int l, r, idx;
	query(int a, int b, int d) : l(a), r(b), idx(d){}

	bool operator<(query xd){
		return make_pair(l/c, r) < make_pair(xd.l/c, xd.r);
	}
};

void skaluj(vector<int>& xd){
	set<pair<int, int>> s;

	int idx = 0;
	REP(i, n) s.insert({xd[i], i});
	int prev = s.begin()->first;
	for(auto [x, i] : s){
		if(x != prev) idx++;
		xd[i] = idx;
		prev = x;
	}
	cnt = vector<int>(idx+1, 0);
}

int main(){
	fast();

	cin >> n;
	c = sqrt(n);

	v = vector<int>(n);
	ITF(e, v) cin >> e;
	skaluj(v);

	// driver code
	vector<query> xd;
	int q;
	cin >> q;
	REP(i, q){
		int l, r;
		cin >> l >> r;
		l--; r--;
		xd.pb(query(l, r, i));
	}

	sort(ALL(xd));
	vector<int> odp(q);

	cnt[v[0]]++;
	ile++;
	int ptrl = 0;
	int ptrr = 0;
	for(auto i : xd){
		while(ptrl < i.l) rem(ptrl++);
		while(ptrl > i.l) add(--ptrl);
		while(ptrr < i.r) add(++ptrr);
		while(ptrr > i.r) rem(ptrr--);
		odp[i.idx] = ile;
	}
	for(auto j : odp) cout << j << '\n';
}