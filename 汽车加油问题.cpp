#include<iostream>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
	int n,k;
	cin >> n;
	cin >> k;
	for(int i = 0; i < k+1; i++)
	   cin >> a[i];
	int sum = a[0];
	int cnt = 0;
	int flag = 0;
	for(int i = 0; i < k+1; i++)
	{
		if(a[i] > n)
		{
		   flag = 1;
		   break;
	    }
	}
	for(int i = 1; i < k+1; i++)
	{
	    if(sum + a[i] > n)
	    {
	       	cnt++;
	        sum = a[i];
        }
	    else
	        sum += a[i];
	}
	if(flag == 0)
	   cout << cnt << endl;
	else
	   cout << "No Solution\n" << endl;
}
