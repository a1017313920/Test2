#include<iostream>
using namespace std;
//const int INT_MAX=2147483647;
int const M=7;
void MATRIX_CHAIN_ORDER(int *p,int Length,int m[][M],int s[][M])
{
	int q,n=Length-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	/* �������ĳ��� */
	{
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         /* �ȼ��� l=j-i+1 */
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
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
}
int main()
{
   int M; 
   int p[M];
   cin>>M;
   for(int i = 1;i <=M+1; i++)
      cin>>p[i];
   int m[M][M],s[M][M];
   MATRIX_CHAIN_ORDER(p,M,m,s);
   cout<<"��n=6ʱ���Ž�Ϊ: \n"<<m[1][6];
   return 0;
}
