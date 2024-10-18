#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pair<int, int> pii

int cross(pii a, pii b, pii c){
	return (b.nd - a.nd) * (c.st - b.st) - (c.nd - b.nd) * (b.st - a.st);
	// 0    = linia prosta    | forward    | geradeaus
	// 0 >  = skręt w prawo   | turn left  | nach links
	// 0 <  = skręt w lewo	  | turn right | nach rechts	
}