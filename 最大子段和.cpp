#include <iostream>

using namespace std;

//int k1,k2;
//-2 11 -5 -3 6 -2
int* MaxSum(int a[],int left,int right)
{
    int center,left_sum,right_sum,s1,s2,lefts,rights,sum,lbesti,lbestj,rbesti,rbestj,mbesti,mbestj;
    int b[3];
    if(left==right)
    {
        if(a[left]>0){
        	b[1]=b[2]=left;
        	b[0]=a[left];
            return b;
        }
        else
        	b[0]=0;
            return b;
    }
    else
    {
        center=(left+right)/2;
        left_sum=*(MaxSum(a,left,center));//计算情况(1)的最大值
        lbesti=*(MaxSum(a,left,center)+1);
        lbestj=*(MaxSum(a,left,center)+2);
        right_sum=*(MaxSum(a,center+1,right));//计算情况(2)的最大值
        rbesti=*(MaxSum(a,center+1,right)+1);
        rbestj=*(MaxSum(a,center+1,right)+2);
        s1=0;
        lefts=0;
        //从中间往两边计算
        for(int i=center;i>=left;i--)
        {
            //计算左边的最大值
            lefts+=a[i];
            if(lefts>s1){
                s1=lefts;
                mbesti=i;
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
                mbestj=i;
            }
        }
        if(s1+s2<left_sum){
            b[0]=left_sum;
            b[1]=lbesti;
            b[2]=lbestj;
        }
        else if(s1+s2<right_sum){
            b[0]=right_sum;
            b[1]=rbesti;
            b[2]=rbestj;
        }
        else
        {
        	b[0]=s1+s2;
            b[1]=mbesti;
            b[2]=mbestj;
		}
    }
    return b;
}

int main()
{
    int a[20],n;
    int* Max;
    printf("输入元素个数:");
    scanf("%d",&n);
    printf("输入元素:");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Max=MaxSum(a,1,n);
    printf("最大元素和为:%d\n",Max[0]);
    printf("从%d到%d",Max[1],Max[2]);
   //printf("从%d到%d",besti1,bestj1);
    return 0;
} 
