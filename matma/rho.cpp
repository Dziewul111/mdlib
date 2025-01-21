#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 i128;
#define abs(x) (x < 0) ? -x : x

LL llmul(LL a, LL b, LL mod){
	return LL((i128) a * b % mod);
}

LL rho(LL n){
	for(LL c = 1;; c++){
		auto f = [&](LL x){return (llmul(x, x, n) + c) % mod;};

		int x = 2, y = f(x), p;

		while((p = gcd(abs(x - y), n)) == 1)
			x = f(x), y = f(f(x));
		if(p != n)
			return p;
	}
}