#include<iostream>
#include <algorithm>
using namespace std;
int a[1000];
int b[1000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
	   cin >> a[i];
    sort(a,a+n);
    for(int i = 0;i < n; i++)
    {
    	for(int j = 0; j <= i; j++)
    	{
    		b[i] += a[j];
		}
	}
	int sum = 0;
	for(int i = 0;i < n; i++)
    {
    	sum += b[i];
    }
    double average = sum/n;
    printf("%.2f",1.0*sum/n);
}
    
   

