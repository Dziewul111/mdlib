#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ITF(e, v) for(auto& e : (v))
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long LL;
typedef pair<int, int> PII;

auto operator<<(auto& o, auto x) -> decltype(x.end(), o){o << '{'; int i = 0; ITF(e, x) o << ','+!i++ << e; return o << '}';}
template<class A, class B>
auto& operator<<(ostream& o, pair<A, B> p){return o << '{' << p.st << ", " << p.nd << '}';}

#ifdef DEBUG
#define LOG(x...) cerr<<"["#x"]: ", [](auto... $){((cerr<<$<<"; "), ...)<<endl;}(x)
#else
#define LOG(...){}
#endif
