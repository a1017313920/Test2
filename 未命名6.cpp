#include<iostream>
#include<cstring> 
using namespace std;
 
const int size=100;
int p[size];
int m[size][size],s[size][size];
int n;
 
void matrixchain()
{
	int i,r,j,k;
	memset(m,0,sizeof(m));
	memset(s,0,sizeof(s));//��ʼ������
	for(r=2;r<=n;r++)//�������˵Ĺ�ģΪr 
	{
		for(i=1;i<=n-r+1;i++)
		{
			j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//��m[][]��ʼ��ֵ
			s[i][j]=i;//s[][]�洢��������ľ��ߵ�
			for(k=i+1;k<j;k++)//Ѱ������ֵ
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t < m[i][j])
				{
					m[i][j]=t;
					s[i] [j]=k;
				}
			}
		}
	}
}
int main()
{
	cin>>n;
	int i;
	for(i=0;i<=n;i++)
		cin>>p[i];
	matrixchain(); 
	cout<<m[1][n]<<endl;
	
	return 0;
}
