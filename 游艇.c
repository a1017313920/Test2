#include<stdio.h>
void MatrixChain(int *p, int n, int **m, int **s) {
	int i;
	for (i = 1; i <= n; i++)
	   m[i][i] = 0;
	int r = 2;
	for (r = 2; r <= n ; r++) {
		for (i = 1; i <= n+r-1; i++) {
			int j=i+r-1;
		}
	}
	
}
