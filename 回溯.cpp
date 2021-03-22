#include<cstdio>
#include<iostream>
using namespace std;
int a[35000];
int f[35000];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=c;j>=a[i];j--)
        {
            f[j]=max(f[j],f[j-a[i]]+a[i]);
        }
    }
    printf("%d\n",f[c]);
    return 0;
}

