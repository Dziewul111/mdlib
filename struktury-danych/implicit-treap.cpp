#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long LL;

mt19937 rng(0);

struct Node{
	Node *left, *right;
	int prior, size;

	LL val; // coś co chcemy trzymac w wierchołku

	Node(int x) : left(0), right(0), prior(rng()), size(1), val(x){}
	Node(){}
};
typedef Node* pNode;

void push(pNode& t){}

inline int get_size(pNode t){
	return (t) ? t->size : 0;
}

void update(pNode& t){
	if(t) t->size = get_size(t->left) + get_size(t->right) + 1;
}

void split(pNode t, pNode& l, pNode& r, int x){
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

void merge(pNode& t, pNode l, pNode r){
	if(!l || !r)
		t = (l) ? l : r;
	else if(l->prior > r->prior){
		push(l);
		merge(l->right, l->right, r), t = l;
	}
	else{
		push(l);
		merge(r->left, l, r->left), t = r;
	}
	update(t);
}

void apply(pNode& root, int l, int r, function<void(pNode)> f){
	pNode a, b, c;

	split(root, a, c, r);
	split(a, a, b, l-1);
	f(b);
	merge(a, a, b);
	merge(root, a, c);
}

void wypisz(pNode t){
	if(!t) return;
	wypisz(t->left);
	cerr << t->val << ' ';
	wypisz(t->right);
}

void insert(pNode& root, int x, int i){
	pNode a, b;

	split(root, a, b, i-1);
	merge(a, a, new Node(x));
	merge(root, a, b);
}


void erase(pNode &root, int i){
	pNode l, m, r;

	split(root, l, r, i);
	split(l, l, m, i-1);
	delete m;
	merge(root, l, r);
}