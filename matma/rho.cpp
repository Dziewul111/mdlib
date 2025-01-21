#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 i128;
#define abs(x) (x < 0) ? -x : x

LL llmul(LL a, LL b, LL mod){
	return LL((i128) a * b % mod);
}

LL rho(LL n){
	if(n % 2 == 0) return 2;
	for(int c = 1;; c++){
		auto f = [&](LL x){return (llmul(x, x, n) + c) % n;};

		LL x = 2, y = f(x), p;

		while((p = gcd(abs(x - y), n)) == 1)
			x = f(x), y = f(f(y));

		if(p != n) return p;
	}
}
