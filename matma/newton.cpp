#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7; // jakaś liczba PIERWSZA (mtf)
const LL maxn = 1e6;

LL fact[maxn], ifact[maxn];

LL exp(LL a, LL b){
    if(b == 0) return 1 % mod;
    LL x = exp(a, b/2) % mod;
    x = (x*x)%mod;
    return x * ((b&1) ? a : 1) % mod;
}

void makefact(){
	fact[0] = fact[1] = 1;

	for(int i = 2; i < maxn; i++)
		fact[i] = (fact[i-1] * i) % mod;

	ifact[maxn-1] = exp(fact[maxn-1], mod - 2);

	for(int i = maxn-2; i >= 0; i--)
		ifact[i] = (ifact[i+1] * (i+1)) % mod;
}

LL binomial(int n, int k){
	assert(n >= k);
	return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}