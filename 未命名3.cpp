#include <iostream>

using namespace std;
int sum; 

int MaxSum(int a[],int left,int right,int &besti,int &bestj)
{
 
    if(left==right)
    {
        if(a[left]>0)
        {
            return a[left];
            besti=bestj=left;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int center=(left+right)/2;
        int besti1,bestj1,besti2,bestj2;
        besti1=bestj1=besti2=bestj2=0;
        int leftsum=MaxSum(a,left,center,besti1,bestj1);
        int rightsum=MaxSum(a,center+1,right,besti2,bestj2);
        int s1,s2,lefts,rights;
        s1=0;
		lefts=0;
        for(int i=center; i>=left; i--)
        {
            lefts+=a[i];
            if(lefts>s1)
            {
                s1=lefts;
                besti=i;
            }
        }
        s2=0;
        rights=0;
        for(int j=center+1; j<=right; j++)
        {
            rights+=a[j];
            if(rights>s2)
            {
                s2=rights;
                bestj=j;
            }
        }
        sum=s1+s2;
        if(leftsum>sum)
        {
            sum=leftsum;
            besti=besti1;
            bestj=bestj1;
        }
        else if(rightsum>sum)
        {
            sum=rightsum;
            besti=besti2;
            bestj=bestj2;
        }
    }
    cout<<"besti="<<besti<<"   bestj="<<bestj<<endl;
        return sum;
}
int main()
{
    int a[20],n,Max,besti3,bestj3;
    printf("输入元素个数:");
    scanf("%d",&n);
    printf("输入元素:");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Max=MaxSum(a,1,n,besti3,bestj3);
    printf("最大元素和为:%d\n",Max);
    //printf("从%d到%d",besti3,bestj3);
    //printf("从%d到%d",besti1,bestj1);
    return 0;
} 

