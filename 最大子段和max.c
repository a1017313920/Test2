#include<stdio.h>
int besti,bestj;
int MaxSubSum(int A[],int left,int right);
void main()
{
	int A[6]={-2,13,-12,11,-15,2};
	int max=MaxSubSum(A,0,5);
	printf("最大字段和为：");
	printf("%d\n",max);
	printf("从%d到%d",besti,bestj);
}
int MaxSubSum(int A[],int left,int right)
{
		int leftsum=0;
		int rightsum=0;
		int s1=0;
		int s2=0;
		int i;
int	center=(left+right)/2;
		if(left==right)
		{
			if(A[left]<0)//题目要求最低值就是0
				return 0;
			else
			{
				return A[left];
				besti=bestj=left;
			}
		}
	 leftsum=MaxSubSum(A,left,center);//递归左子问题
     int leftsum=sum;
     int lbesti=besti;
     int lbestj=bestj;
	 rightsum=MaxSubSum(A,center+1,right);//递归右子问题
	 int rightsum=sum;
     int rbesti=besti;
     int rbestj=bestj;
	 s1=A[center];//存放从中间开始到左边的最大连续子段
	 s2=A[center+1];//存放从中间开始到右边的最大连续子段
	 int temp1=A[center];//临时变量
	 int temp2=A[center+1];
	 int mbesti=1;
	 int mbestj=1;
	 for( i=center-1;i>=0;i--)//求出S1的最大连续值
	 {	
		 
		 temp1=A[i]+temp1;//从中间到左边一直求值
		 if(s1<temp1)
			 s1=temp1;//从中间到左边一直求值,s1为最大值
			 mbesti=i;
	 }

	 for( i=center+2;i<=right;i++)//求出S2的最大连续值
	 {
		  temp2=A[i]+temp2;
		 if(s2<temp2)
			 s2=temp2;
			 mbestj=i;
		 
	 }
	 int sum=s1+s2;
	 if(leftsum>sum)
	 {
		 sum=leftsum;
		 besti=lbesti;
        bestj=lbestj;
    }
	 if(rightsum>sum)
	 {
	 	    sum=rightsum;//rightSum表示后段序列的最大字段和
            besti=rbesti;
            bestj=rbestj;
	 }
	 return sum;//返回该递归中最大的哪一个值

}
