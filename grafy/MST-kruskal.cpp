#include <bits/stdc++.h>
#include "../struktury-danych/union_find.cpp"
using namespace std;
#define pb push_back

struct edge{
	int a, b, weight;
};

vector<edge> kruskal_mst(vector<edge> edges, int n){ // n - ile wierzchołków
	sort(edges.begin(), edges.end(), [](edge a, edge b){return a.weight < b.weight;});

	vector<edge> ret;
	union_find u(n);

	for(edge e : edges){
		if(!u.find(e.a, e.b)){
			ret.pb(e);
			u.unite(e.a, e.b);
		}
	}
	return ret;
}

