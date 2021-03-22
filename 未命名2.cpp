#include <iostream>

using namespace std;

int besti,bestj;
int besti1,bestj1,besti2,bestj2;
//-2 11 -5 -3 6 -2
int MaxSum(int a[],int left,int right,int besti3,int bestj3)
{
    int center,left_sum,right_sum,s1,s2,lefts,rights,sum;
    if(left==right)
    {
        if(a[left]>0){
        	besti1=bestj1=left;
            return a[left];
        }
        else
            return 0;
    }
    else
    {
        center=(left+right)/2;
        left_sum=MaxSum(a,left,center,besti1,bestj1);//计算情况(1)的最大值
        right_sum=MaxSum(a,center+1,right,besti2,bestj2);//计算情况(2)的最大值
        s1=0;
        lefts=0;
        //从中间往两边计算
        for(int i=center;i>=left;i--)
        {
            //计算左边的最大值
            lefts+=a[i];
            if(lefts>s1){
                s1=lefts;
                besti=i;
            }
        }
        s2=0;
        rights=0;
        for(int i=center+1;i<=right;i++)
        {
            //计算右边的最大值
            rights+=a[i];
            if(rights>s2){
                s2=rights;
                bestj=i;
            }
        }
        if(s1+s2<left_sum){
            sum=left_sum;
            besti=besti1;
            bestj=bestj1;
        }
        else if(s1+s2<right_sum){
            sum=right_sum;
            besti=besti2;
            bestj=bestj2;
        }
        else
        {
        	sum=s1+s2;
		}
    }
    return sum;
    
}

int main()
{
    int a[20],n,Max;
    printf("输入元素个数:");
    scanf("%d",&n);
    printf("输入元素:");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Max=MaxSum(a,1,n,besti,bestj);
    printf("最大元素和为:%d\n",Max);
    //printf("从%d到%d",besti,bestj);
    //printf("从%d到%d",besti1,bestj1);
    return 0;
} 
