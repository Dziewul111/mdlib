#include<bits/stdc++.h>
#include "mat-mul.cpp"
using namespace std;
#define ssize(x) x.size()
#define matrix vector<vector<int>> 

matrix matexp(matrix& m1, int exp){
	assert(ssize(m1) == ssize(m1[0]));

	if(exp == 1)
		return m1;
	else if(exp % 2 == 0)
		return matexp(matmul(m1, m1), exp/2);
	else
		return matmul(m1, matexp(m1, m1), exp/2);
}