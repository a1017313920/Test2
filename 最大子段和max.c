#include<stdio.h>
int besti,bestj;
int MaxSubSum(int A[],int left,int right);
void main()
{
	int A[6]={-2,13,-12,11,-15,2};
	int max=MaxSubSum(A,0,5);
	printf("����ֶκ�Ϊ��");
	printf("%d\n",max);
	printf("��%d��%d",besti,bestj);
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
			if(A[left]<0)//��ĿҪ�����ֵ����0
				return 0;
			else
			{
				return A[left];
				besti=bestj=left;
			}
		}
	 leftsum=MaxSubSum(A,left,center);//�ݹ���������
     int leftsum=sum;
     int lbesti=besti;
     int lbestj=bestj;
	 rightsum=MaxSubSum(A,center+1,right);//�ݹ���������
	 int rightsum=sum;
     int rbesti=besti;
     int rbestj=bestj;
	 s1=A[center];//��Ŵ��м俪ʼ����ߵ���������Ӷ�
	 s2=A[center+1];//��Ŵ��м俪ʼ���ұߵ���������Ӷ�
	 int temp1=A[center];//��ʱ����
	 int temp2=A[center+1];
	 int mbesti=1;
	 int mbestj=1;
	 for( i=center-1;i>=0;i--)//���S1���������ֵ
	 {	
		 
		 temp1=A[i]+temp1;//���м䵽���һֱ��ֵ
		 if(s1<temp1)
			 s1=temp1;//���м䵽���һֱ��ֵ,s1Ϊ���ֵ
			 mbesti=i;
	 }

	 for( i=center+2;i<=right;i++)//���S2���������ֵ
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
	 	    sum=rightsum;//rightSum��ʾ������е�����ֶκ�
            besti=rbesti;
            bestj=rbestj;
	 }
	 return sum;//���ظõݹ���������һ��ֵ

}
