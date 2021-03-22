#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100],b[100];
int dp[100][100];
int c[100][100]={0};
char d[100];
char e[100];
int max_len=0;
int k=0;
void LCS(int i, int j, char *a, int **c)
{
	if (i == 0 || j == 0)
	{
		return ;
	}
	for(int i1 = i;i1 > 0; i1--)
	{
		for(int j1 = j;j1 > 0; j1--)
		{
			int i2 = i1;
			int j2 = j1;
			if (c[i2][j2] == 1)
	        {
	            d[k] = a[i2 - 1];
		        cout<<d[k];
	         	k++;
	         	i2--;
	         	j2--;
        	}
		}
	}
}
int main(){
     int i,j;
     int n,m;
     //char result;
     cin.getline(a,101);
     cin.getline(b,101);
     n = strlen(a);
     m = strlen(b);
     int **c = new int *[100];
	 int **dp = new int *[100]; 
	 for(int i=0;i<=100;i++) { 
	 c[i] = new int[100]; 
	 dp[i] = new int[100]; 
	 }
     for (i = 0;i< n; i++){
         for (j = 0;j< m;j++){
             if (a[i] == b[j]){
             	 c[i][j] = 1;
                 if (i > 0&&j > 0){
                     dp[i][j] = dp[i-1][j-1] + 1;
                 } else {
                     dp[i][j] = 1;
                 }
                 if (max_len < dp[i][j]){
                     max_len = dp[i][j];
                 }
             }
             else
                c[i][j] = 0;
         }
     }
     //cout<<max_len;
      if(max_len <= 0)
	   cout<<"NO"<<endl;
	  else{
	     if(n >= m)
	        LCS(i, j, a, c);
	     else
	        LCS(i, j, b, c);
	}
	//for(int i=0;i<k;i++)
	//    cout<<d[i];
	
    return 0;
}
