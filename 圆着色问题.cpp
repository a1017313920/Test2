#include <iostream>
using namespace std;
#include<cstring>
#include<math.h>
int n;
int m;
int k;
int sum=0;
int x[101];
int a[101][101];
bool OK(int t)
{
    for(int i=1;i<t;i++)
        if(a[i][t]==1&&x[i]==x[t])
            return false;
    return true;
}
void getsum(int i)
{
    if(i>n){
        sum++;
        return ;
    }
    else{
        for(int k=1;k<=m;k++){
            x[i]=k;
            if(OK(i))
                getsum(i+1);
            x[i]=0;
        }
    }
    return ;
}
int main()
{
    cin>>n>>k>>m;
    int x,y;
    memset(a,0,sizeof(a));
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    getsum(1);
    cout<<sum;
    return 0;
}
