#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define ssize(x) x.size()
#define inf INT_MAX
typedef long long LL;

vector<int> dijkstra(vector<vector<pair<int, LL>>>& adj, int u){
	int n = ssize(adj);

	priority_queue<pair<LL, int>> q;
	vector<int> odl(n, inf);
	vector<bool> odw(n, 0);
	q.push({0, u});

	while(ssize(q)){
		LL w = q.top().nd;
		q.pop();

		if(odw[w])
			continue;

		odw[w] = 1;

		for(auto i : adj[w]){
			if(odl[i.st] > odl[w] + i.nd){
				odl[i.st] = odl[w] + i.nd;
				q.push({-odl[i.st], i.st});
			}
		}
	}
	return odl;
}