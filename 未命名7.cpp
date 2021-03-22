#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100],b[100];
int c[100][100];
int d[100][100];
void print_lcs(int i, int j, char *a, int **d)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (d[i][j] == 0)
	{
		print_lcs(i - 1, j - 1, a, d);
		printf("%c", a[i - 1]);
	}
	else if (d[i][j] == 1)
	{
		print_lcs(i - 1, j, a, d);
	}
	else
	{
		print_lcs(i, j - 1, a, d);
	}
}
int main(){
     int i,j,max_len = 0;
     int len1,len2,result;
     cin.getline(a,101);
     cin.getline(b,101);
     int **c = new int *[100];
	 int **d = new int *[100]; 
	 for(int i=0;i<=strlen(a);i++) { 
	 c[i] = new int[100]; 
	 d[i] = new int[100]; 
	 }
	 len1 = strlen(a);
	 len2 = strlen(b);
	 /*
     for (i = 0;i< strlen(a); i++){
         for (j = 0;j< strlen (b);j++){
             if (a[i] == b[j]){
                 if (i > 0&&j > 0){
                     dp[i][j] = dp[i-1][j-1]+1;
                     c[i][j] = 0;
                 } else {
                     dp[i][j] = 1;
                 }
                 if (max_len < dp[i][j]){
                     max_len = dp[i][j];
                 }
             }
         }
     }
     */
     for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				d[i][j] = 0;
				result = c[i][j] > result ? c[i][j] : result;
			}
			else {
				c[i][j] = 0;
			}
		}
	}
     if(result == 0)
	   cout<<"NO";
	 else
     print_lcs(i, j, a, d);
     return 0;
}
