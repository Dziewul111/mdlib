#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;

mt19937 rng(0);

struct Node{
	Node *left, *right;
	int prior, size;

	LL val; // coś co chcemy trzymac w wierchołku

	Node(int x) : prior(rng()), size(1), val(x){}
	Node(){}
};
typedef Node* pnode;

void push(pnode& t){}

inline int get_size(pnode t){
	return (t) ? t->size : 0;
}

void update(pnode& t){
	t->size = get_size(t->left) + get_size(t->right) + 1;
}

void split(pnode t, pnode& l, pnode& r, int x){
	if(!t){
		l = r = nullptr;
		return;
	}
	push(t);
	if(get_size(t->left) <= x)
		split(t->right, t->right, r, x-get_size(t->left)-1), l = t;
	else
		split(t->left, l, t->left, x), r = t;
	update(t);
}

void merge(pnode& t, pnode l, pnode r){
	if(!l || !r)
		t = (l) ? l : r;
	else if(l->prior > r->prior){
		push(l);
		merge(l->right, l->right, r), t = l;
	}
	else{
		push(r);
		merge(r->left, l, r->left), t = r;
	}
	update(t);
}

void apply(pnode& root, int l, int r, function<void(pnode)> f){
	pnode a, b, c;

	split(root, a, c, r);
	split(a, a, b, l-1);
	f(b);
	merge(a, a, b);
	merge(root, a, c);
}

void wypisz(pnode t){
	if(!t) return;
	wypisz(t->left);
	cerr << t->val << ' ';
	wypisz(t->right);
}
