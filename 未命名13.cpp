#include<iostream>
#include<cstring>
using namespace std;
int m[1000][1000],s[1000][1000];
int p[1000];

int main()
{
    int n,i,j,r,k;
    cin>>n;
    for(int i = 0; i <= n; i++)
       cin>>p[i];
    for(int i = 1;i <= n; i++) 
	    m[i][i] = 0;
	for(r=2;r<=n;r++)
	{
		for(i = 1;i <= n-r+1; i++)
		{
			j = i+r-1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(k = i+1;k < j; k++)
			{
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
   cout<<m[1][n]<<endl;
   return 0;
}
