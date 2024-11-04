#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
int rd(int l, int r){
	return uniform_int_distribution<int>(l, r)(rng);
}

long long rd_ll(long long l , long long r){
	return uniform_int_distribution<long long>(l, r)(rng);
}
