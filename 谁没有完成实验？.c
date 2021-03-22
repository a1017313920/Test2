#include<stdio.h>
int main()
{
	int i,j;
	int n,m;
    int a[20000],b[100];
	scanf("%d",&n);
	for(i = 0;i < n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(j = 0;j < m; j++)
	    scanf("%d",&b[j]);
	for(j = 0;j < m; j++){
	   int flag = 0;
	   int low,high,mid;
       low = 0;
       high = n-1;
       while(low <= high)   
       {
        mid = (low + high) / 2;  
        if(b[j] < a[mid])   
            high = mid - 1;    
        else if(b[j] > a[mid])    
            low = mid + 1;    
        else if(b[j] == a[mid])  
        {
               flag = 1;
               break;
        }
        }
	    if(flag == 1)
	       printf("Yes\n");
	    else
	       printf("No\n");  
	   }
}
