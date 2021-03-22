#include <iostream>
#include <math.h>
using namespace std;
const int maxn=100005;
int n;
float minx=1e7;
float x[maxn]={0},r[maxn]={0};
float center(int t)//计算t圆的圆心x坐标
{
    float res=0;
    for(int i=0;i<t;i++)
    {//(rt+rj)^2-(rt-rj)^2=4*rj*rt
        float temp=x[i]+2.0*sqrt(r[t]*r[i]);
        if(temp>res) res=temp; 
    }
    return res;
}
void compute()
{
    float low=0,high=0;
    for(int i=0;i<n;i++)
    {
        float tempLow=x[i]-r[i];
        float rempHigh=x[i]+r[i];
        if(tempLow<low) low=tempLow;
        if(rempHigh>high) high=rempHigh;
    }
    if(high-low<minx) minx=high-low;
}
void circleBacktrace(int t)
{
    if(t>=n) compute();//更新minx
    else{
        for(int i=t;i<n;i++)
        {
            swap(r[t],r[i]);
            float c=center(t);//圆心
            if(c+r[t]+r[0]<minx)
            {
                x[t]=c;
                circleBacktrace(t+1);
            }
            swap(r[t],r[i]);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>r[i];
    circleBacktrace(0);
    printf("%.5f\n",minx);
    system("pause");
    return 0;
}
/*
3
1 1 2
*/
