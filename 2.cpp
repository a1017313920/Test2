#include <stdio.h>
int binary_search(int key,int a[],int n) 
{
    int low,high,mid,count=0,count1=0;
    low=0;
    high=n-1;
    while(low<=high)   
    {
        count++;     //���ز��ҵ��ܴ���
        mid=(low+high)/2;  
        if(key<a[mid])   
            high=mid-1;    
        else if(key>a[mid])    
            low=mid+1;    
        else if(key==a[mid])  
        {
            printf("%d\n%d\n",mid,count);   
            count1++;      //���سɹ��Ĵ���
            break;
        }
    }
    if(count1==0)   
        printf("-1\n%d",count);
    return 0; 
}
int main()
{
    int i,key,a[100],n;
    scanf("%d",&n);    //����Ԫ�ظ���
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);  //��������Ԫ�ظ�ֵ
    scanf("%d",&key);       //����Ҫ���ҵ�Ԫ��
    binary_search(key,a,n);
    return 0;
}
