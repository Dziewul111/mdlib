#include<bits/stdc++.h>
typedef long long LL;

struct congruence{
	LL a, m;
};

LL crt(vector<congruence>& v){
	LL m = 1, ans = 0;

	for(auto& c : v)
		m *= c.m;

	for(auto& c : v){
		LL M = m / c.m;
		LL N = binexp(M, phi[c.m] - 1, c.m);

		ans += (c.a * M * N);
		ans %= m;
	}
	return ans;
}	