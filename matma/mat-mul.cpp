#include<bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int>> 
#define ssize(x) x.size()

matrix matmul(matrix a, matrix b){
	assert(ssize(a) == ssize(b[0]));
	assert(ssize(a[0]) == ssize(b));

	int a = ssize(a);
	int b = ssize(a[0]);
	int d = ssize(b[0]);

	matrix ret(a, vector<int>(d, 0));

	for(int i = 0; i < a; i++)
		for(int j = 0; j < d; j++)
			for(int k = 0; k < b; k++)
				ret[i][j] += a[i][k] * b[k][j];

	return ret;
}
