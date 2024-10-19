#include <bits/stdc++.h>
using namespace std;   // Mateusz Dziewulski
typedef long long LL;  // XIII LO Szczecin
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
#define st first
#define nd second
#define pb push_back
#ifdef DEBUG
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
		return o << '(' << p.st << ", " << p.nd << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
		o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#define LOG(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define LOG(x...){}
#endif


struct union_find{
	vector<int> link;
	vector<int> size;

	union_find(int n){
		size.resize(n, 1);
		link.resize(n);
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

struct edge{
	int a, b, weight;
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<edge> edges(m);

	for(auto& e : edges){
		cin >> e.a >> e.b >> e.weight;
		e.a--; e.b--;
	}

	sort(edges.begin(), edges.end(), [](edge a, edge b){return a.weight < b.weight;});

	int sum = 0;
	vector<int> MST;
	union_find u(n);

	for(edge e : edges){
		if(!u.find(e.a, e.b)){
			MST.pb(a);
			MST.pb(b);
			u.unite(e.a, e.b);
			sum += e.weight;
		}
	}
}