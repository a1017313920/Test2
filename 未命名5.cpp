
#include<iostream>
using namespace std;
//const int INT_MAX=2147483647;
int const M=7;
int main()
{
   int p[M]={30,35,15,5,10,20,25};
   int m[M][M],s[M][M];
   int q,n=7-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	/* 矩阵链的长度 */
	{
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         /* 等价于 l=j-i+1 */
			m[i][j]=2147483647;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<"当n=6时最优解为: \n"<<m[1][6];
   return 0;
}
