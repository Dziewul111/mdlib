#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
typedef long long LL;

/* taka skbidi strukturka

~> k-ty najmniejszy element w przedziale [l, r] O(szybko)
~> suma elementów <= k w [l, r] O(szybko)
~> suma k najmniejszych elementów w [l, r] O(szybko)
i da sie jeszcze wiele innych rzeczy na tym zrobic ale mi sie nie chce
*/

struct wavelet_tree{
	wavelet_tree *l, *r;
	vector<LL> b, pref;
	LL lo, hi;

	wavelet_tree(LL* from, LL* to, LL x, LL y) : lo(x), hi(y){
		if(to <= from)
			return;

		LL mid = (lo + hi) / 2;

		auto f = [mid](LL n){return n <= mid;};

		b.pb(0);
		pref.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it)), pref.pb(pref.back() + *it);

		if(lo != hi){
			auto pivot = stable_partition(from, to, f);
			l = new wavelet_tree(from, pivot, lo, mid);
			r = new wavelet_tree(pivot, to, mid+1, hi);
		}
	}

	wavelet_tree(vector<LL> v){
		LL mx = numeric_limits<LL>::min(), mn = numeric_limits<LL>::max();
		for(LL e : v)
			mx = max(mx, e), mn = min(mn, e);
		*this = wavelet_tree(&v[0], &v[0] + v.size(), mn, mx);
	}

	void wypisz(){
		cout << lo << ' ' << hi << ' ' << b.size() << endl;
		if(l)
			l->wypisz();
		if(r) 
			r->wypisz();
	}

	LL kth(LL l, LL r, LL k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		LL inLeft = b[r] - b[l-1];
		LL lb = b[l-1];  
		LL rb = b[r];
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}

	LL sumk(LL l, LL r, LL k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return pref[r] - pref[l-1];
		LL lb = b[l-1], rb = b[r];
		return this->l->sumk(lb+1, rb, k) + this->r->sumk(l-lb, r-rb, k);
	}

	LL sumk_smallest(LL l, LL r, LL k){
		if(l > r) return 0;
		if(lo == hi) return lo * k;
		if(r - l < k)
			return pref[r] - pref[l-1];
		LL inLeft = b[r] - b[l-1];
		LL lb = b[l-1];  
		LL rb = b[r];
		if(k <= inLeft) return this->l->sumk_smallest(lb+1, rb , k);
		return this->r->sumk_smallest(l-lb, r-rb, k-inLeft)\
				+ this->l->sumk_smallest(lb+1, rb, inLeft); 
	}
};

