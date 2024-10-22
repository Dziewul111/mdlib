#include<bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int>> 
#define ssize(x) x.size()

matrix matmul(matrix m1, matrix m2){
	assert(ssize(m1) == ssize(m2[0]));
	assert(ssize(m1[0]) == ssize(m2));

	int a = (int)ssize(m1);
	int b = (int)ssize(m1[0]);
	int d = (int)ssize(m2[0]);

	matrix ret(a, vector<int>(d, 0));

	for(int i = 0; i < a; i++)
		for(int j = 0; j < d; j++)
			for(int k = 0; k < b; k++)
				ret[i][j] += m1[i][k] * m2[k][j];

	return ret;
}