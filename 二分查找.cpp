#include <iostream>
void MergeSort(int a[], int n){
	int *b = new int [n];
	int s = 1;
	while(s < n){
		MergePass(a, b, s, n);
		s += s;
		MergePass(b, a, s, n);
		s += s;
	} 
}
void MergePass(int x[], int y[], int s, int n){
	int i = 0;
	while(i < n - 2 * s){
		Merge(x, y, i, i+s-1, i+2*s-1);
		i = i+2*s;
	}
	if(i+s<n)
	   Merge(x, y, i, i+s-1, n-1);
	else
	   for(int j=i; j<=n-1;j++)
	      y[j] = x[j];
}
void Merge(int c[], int d[], int l, int m, int r){
	int i = 1, j = m+1, k=l;
	while((i<=m) && (j<=r)){
		if(c[i]<=c[j])
		   d[k++] = c[i++];
		else
		   d[k++] = c[j++];
		if(i>m){
			for(int q=j; q<=r; q++)
			   d[k++] = c[q];
		}
		else{
			for(int q=i; q<=m; q++)
			d[k++] = c[q];
		}
	}
}
int main()
{
	MergeSort(); 
} 
