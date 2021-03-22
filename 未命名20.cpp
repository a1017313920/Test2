#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100],b[100];
int dp[100][100];
int c[100][100];
char d[100];
int max_len=0;
int k=0;
void LCS(int i, int j, char *a, int **c)
{
	if (i == 0 || j == 0)
	{
	}
	if (c[i][j] == 0)
	{
		LCS(i - 1, j - 1, a, c);
		//if(k%max_len == 0 && k != 0)
		//  printf("\n");
		d[k] = a[i - 1];
		cout<<d[k];
		k++;
	}
	else if (c[i][j] == 1)
	{
		LCS(i, j - 1, a, c);
	}
	else
	{
		LCS(i - 1, j, a, c);
	}
}
int main(){
     int i,j;
     cin.getline(a,101);
     cin.getline(b,101);
     int **c = new int *[100];
	 int **d = new int *[100]; 
	 for(int i=0;i<=100;i++) { 
	 c[i] = new int[100]; 
	 d[i] = new int[100]; 
	 }
     for (i = 0;i< strlen(a); i++){
         for (j = 0;j< strlen (b);j++){
             if (a[i] == b[j]){
             	 c[i][j] = 0;
                 if (i > 0&&j > 0){
                     dp[i][j] = dp[i-1][j-1] + 1;
                 } else {
                     dp[i][j] = 0;
                 }
                 if (max_len < dp[i][j]){
                     max_len = dp[i][j];
                 }
             }
         }
     }
     //cout<<max_len;
     if(max_len == 0)
	   cout<<"NO"<<endl;
	 else
	 LCS(i, j, a, c);
     return 0;
}
