#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef __int128 i128;

LL exp(LL a, LL b, LL mod) {
    LL res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1)
            res = (i128)res * a % mod;
        a = (i128)a * a % mod;
        b >>= 1;
    }
    return res;
}

bool iscomposite(LL n, LL s, LL a, LL d){
	LL x = exp(a, d, n);
	if(x == n - 1 || x == 1) return 0;

	for(LL i = 1; i < s; i++){
		x = (i128)x * x % n;
		if(x == n - 1) return 0;
	}
	return 1;
}

bool isprime(LL x){
	if(x % 2 == 0) return x == 2;
	LL d = x - 1, r = 0;

	while(d % 2 == 0)
		r++, d >>= 1;

	for(LL a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
		if(a == x) return 1;	
		if(iscomposite(x, r, a, d)) return 0;
	}
	return 1;
}