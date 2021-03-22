#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100],b[100];
int dp[100][100];
int c[100][100];
void print_lcs(int i, int j, char *a, int **c)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (c[i][j] == 0)
	{
		print_lcs(i - 1, j - 1, a, c);
		printf("∫Û√Ê%c", a[i - 1]);
	}
	else if (c[i][j] == 1)
	{
		print_lcs(i - 1, j, a, c);
	}
	else
	{
		print_lcs(i, j - 1, a, c);
	}
}
int main(){
     int i,j,max_len = 0;
     cin.getline(a,101);
     cin.getline(b,101);
     int **c = new int *[100];
	 int **d = new int *[100]; 
	 for(int i=0;i<=strlen(a);i++) { 
	 c[i] = new int[100]; 
	 d[i] = new int[100]; 
	 }
     for (i = 0;i< strlen(a); i++){
         for (j = 0;j< strlen (b);j++){
             if (a[i] == b[j]){
                 if (i > 0&&j > 0){
                     dp[i][j] = dp[i-1][j-1] + 1;
                     c[i][j] = 0;
                 } else {
                     dp[i][j] = 0;
                 }
                 if (max_len < dp[i][j]){
                     max_len = dp[i][j];
                 }
             }
         }
     }
     if(max_len == 0)
	   cout<<"NO";
	 else
     print_lcs(i, j, a, c);
     return 0;
}
