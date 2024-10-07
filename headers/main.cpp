#include <bits/stdc++.h>
using namespace std;   // Mateusz Dziewulski
typedef long long LL;  // XIII LO Szczecin
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
#define st first
#define nd second
#define pb push_back
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.st << ", " << p.nd << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#define LOG(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'

int main(){
  cin.tie(0)-sync_with_stdio(0);
}
