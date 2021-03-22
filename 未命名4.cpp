#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char a[100]={0};
char b[100]={0};
int c[100][100]={0};
int d[100][100]={0};

void LCS(int i,int j, char *a, int**d) {
	if (i == 0 || j == 0)
	    return;
	if(d[i][j] == 1) {
		LCS(i-1, j-1, a, d);
		cout<<a[i];
	}
	else if (d[i][j] == 2)
	    LCS(i-1, j, a, d);
	else
	    LCS(i, j-1, a, d);
}
int main(){
    int i=0,j=0;
    cin.getline(a,101);
    cin.getline(b,101); 
    int m = strlen(a);
    int n = strlen(b);
    int **c = new int *[100];
	int **d = new int *[100]; 
	for(int i=0;i<=m;i++) { 
	c[i] = new int[100]; 
	d[i] = new int[100]; 
	}
    for(i = 1; i <= m; i++)
        c[i][0] = 0;
    for(i = 1; i <= n; i++)
        c[0][i] = 0;
    for(i = 1;i <= m; i++) {
    	for(j = 1; j <=n; j++) {
    		if(a[i-1] == b[j-1]) {
    			c[i][j] = c[i-1][j-1] + 1;
    			d[i][j] = 1;
    	}
    	else if (c[i-1][j] >= c[i][j-1]) {
    		c[i][j] = c[i-1][j];
    		d[i][j] = 2;
		}
		else {
			c[i][j] = c[i][j-1];
			d[i][j] = 3;
			}
		}
	}
	cout<<c[m][n]<<endl;
	if(c[m][n] == 0)
	   cout<<"No";
	else
	LCS(m, n, a, d);
    return 0;
}
