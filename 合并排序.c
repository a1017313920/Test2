#include <malloc.h>
#include <stdlib.h>
void mergesort(int A[],int n)  //�ϲ�����ĵݹ�����
{
    void merge(int A[], int L[], int R[], int l, int r);  //����merge����
    if(n>1)    //����һ��Ԫ�ز���Ҫ����
    {
    	int i,j; 
        int mid=n/2;
        int *left=(int*)malloc(sizeof(int)*mid);
        int *right=(int*)malloc(sizeof(int)*(n-mid));
        for(i=0;i<mid;i++)
            left[i]=A[i];       //������ʱ����洢��벿������
        for(j=mid;j<n;j++)
            right[j-mid]=A[j];  //������ʱ����洢�Ұ벿������
 
        mergesort(left,mid);    //�����������벿�ֽ��кϲ�����
        mergesort(right,n-mid); //����������Ұ벿�ֽ��кϲ�����
        merge(A,left,right,mid,n-mid);   //�����������еĺϲ���������װΪ����
        free(left);
        free(right);
    }
}
 
void merge(int A[],int L[],int R[],int l,int r)  //������������L��R�ϲ�ΪA��l,r�ֱ�ΪL,R�ĳ���
{
    int i=0,j=0,k=0;
    while(i<l&&j<r)  //������������Ԫ�����Ƚϣ�С��ȡ�����븸����
    {
        if(L[i]<=R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<l)       //����벿��ʣ��Ԫ�����븸����
    {
        A[k++]=L[i++];
    }
    while(j<r)       //���Ұ벿��ʣ��Ԫ�����븸����
    {
        A[k++]=R[j++];
    }
}

