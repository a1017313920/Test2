#include <iostream>
#include <algorithm>
using namespace std;
float v[1000];
float w[1000];
float x[1000];
void Sort(int n, float v[], float w[])
{
	int temp;
	for(int i = 0; i < n; i++)
	   for(int j = 0; j <= n; j++)
	   {
	   	if(v[i]/w[i]<v[j]/w[j])
	   	   temp = i;
	   	   i = j;
	   	   j = temp;
	   }
}
void Knapsack(int n, float M, float v[], float w[], float x[]) 
{
	Sort(n, v, w);
	int i;
	for(i = 1; i <= n; i++)
	   x[i] = 0;
	float c = M;
	for(i = 1; i <= n ; i++) {
		if(w[i]>c)
		   break;
		x[i] = 1;
		c -= w[i];
	}
	if(i <= n)
	  x[i] = c/w[i];
}
int main()
{
	int n;
	float m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	   cin >> w[i];
	for(int i = 0; i < n; i++)
	   cin >> v[i];
	Knapsack(n,m,v,w,x);
	float sum = 0;
	for(int i = 0; i < n; i++)
	   cout << v[i] <<endl;
	for(int i = 0; i < n; i++)
	{
		sum += x[i]*v[i];
	}
	cout << sum;
} 
