#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
	int n,l;
	cin >> n >> l;
	for(int i = 0; i < n; i++)
	   cin >> a[i];
	sort(a,a+n);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		l -= a[i];
		if(l>=0) 
		  cnt++;
		else
		  break;
	}
	cout << cnt;
} 
