#include<bits/stdc++.h>
#include"miller-rabin.cpp"
#include"rho.cpp"
using namespace std;
typedef long long LL;

void factorize(LL x, map<LL, int>& Vp){
	if(isprime(x)){
		Vp[x]++;
		return;
	}

	LL d = rho(x);

	factorize(d, Vp);
	factorize(x/d, Vp);
}