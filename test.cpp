#include<stdio.h>
const int left=0;
const int right=1;
int s[100005];
int f[100005][2];
int c[100005];
int n;
int refresh(int k)
{
    int i=k;
    while (f[i][left]==1)
    {
        if (c[i-1]<=c[i]) c[i-1]=c[i]+1;
        i=i-1;
    }
    i=k;
    while (f[i][right]==1)
    {
        if (c[i+1]<=c[i]) c[i+1]=c[i]+1;
        i=i+1;
    }
    return 0;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            f[i][left]=0;
            f[i][right]=0;
            c[i]=0;
        }
        for (int i=0;i<n;i++)
            scanf("%d",&s[i]);
        if (s[1]>s[0]) f[0][right]=1;
        for (int i=1;i<n-1;i++)
        {
            if (s[i-1]>s[i]) f[i][left]=1;
            if (s[i+1]>s[i]) f[i][right]=1;
        }
        if (s[n-2]>s[n-1]) f[n-1][left]=1;
        if (f[1][left]==0)
        {
            c[0]=1; 
            refresh(0);
        }
        for (int i=1;i<n-1;i++)
            if (f[i-1][right]==0 && f[i+1][left]==0) 
            {
                c[i]=1;
                refresh(i);
            }
        if (f[n-2][right]==0) 
        {
            c[n-1]=1;
            refresh(n-1);
        }
        long sum=0;
        for (int i=0;i<n;i++)
            sum+=c[i];
        printf("%ld\n",sum);
    }
    return 0;
}
