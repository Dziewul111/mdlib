#include<bits/stdc++.h>
using namespace std;
#define size(x) int(x.size())
#define all(x) x.begin(), x.end()
typedef long long ll;


typedef complex<double> cd;

const double PI = acos(-1);

void fft(vector<cd>& A, bool invert){
	int n = size(A);
	if(n == 1){
		return;
	}

	vector<cd> A0(n/2), A1(n/2);
	for(ll i = 0; i < n/2; i++){
		A0[i] = A[2 * i];
		A1[i] = A[2 * i + 1];
	}
	fft(A0, invert);
	fft(A1, invert);
	double angle = ((2 * PI) / n) * ((invert) ? -1 : 1);
	cd cur = 1, mult(cos(angle), sin(angle));
	for(ll i = 0; i < n/2; i++){
		A[i] = A0[i] + cur * A1[i];
		A[i + (n/2)] = A0[i] - cur * A1[i];
		cur *= mult;
	}
}

vector<ll> multiplyPolynomials(vector<ll>& A, vector<ll>& B){
	vector<cd> Ac(all(A)), Bc(all(B));
	int n = 1;
	while(n < size(A) + size(B))
		n *= 2;
	Ac.resize(n, 0);
	Bc.resize(n, 0);

	fft(Ac, 0);
	fft(Bc, 0);

	for(ll i = 0; i < n; i++)
		Ac[i] = Ac[i] * Bc[i];

	fft(Ac, 1);
	
	vector<ll> ret(n);
    for (ll i = 0; i < n; i++)
        ret[i] = ll(round(Ac[i].real() / n));
    return ret;
}
