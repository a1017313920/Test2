#include <stdio.h>
int binary_search(int key,int a[],int n) 
{
    int low,high,mid,count=0,count1=0;
    low=0;
    high=n-1;
    while(low<=high)   
    {
        count++;     //返回查找的总次数
        mid=(low+high)/2;  
        if(key<a[mid])   
            high=mid-1;    
        else if(key>a[mid])    
            low=mid+1;    
        else if(key==a[mid])  
        {
            printf("%d\n%d\n",mid,count);   
            count1++;      //返回成功的次数
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
    scanf("%d",&n);    //输入元素个数
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);  //对其数组元素赋值
    scanf("%d",&key);       //输入要查找的元素
    binary_search(key,a,n);
    return 0;
}
