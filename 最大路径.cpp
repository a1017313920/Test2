#include <iostream>
using namespace std;
int main()
{
    int n,i,j,k,p;
    int a[100][100];
    cin>>n;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= i; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i = 1;i <= n; i++)
    {
        for(j = i;j <= i; j++)
        {
        	a[i][j] += a[i][j];
        }
    }
    cout<<a[1][n]<<endl;
    return 0;
}
