#include <iostream>
using namespace std;
int main()
{
    int n,i,j,k,p;
    int a[100][100];
    cin>>n;
    for(i = 1; i<=n; i++)
    {
        a[i][i] = 0;
    }
    for(i = 1;i <= n; i++)
    {
        for(j = i+1;j <= n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i = 2;i <= n; i++)
    {
        for(j = i+1;j <= n; j++)
        {
            k = j-i;
            for(p = k;p < j; p++)
            {
                if(a[k][j] > a[k][p]+a[p][j])
                a[k][j] = a[k][p]+a[p][j];
            }
        }
    }
    cout<<a[1][n]<<endl;
    return 0;
}
