#include<stdio.h> 

int main()
{
	int i,n;
	int count[10] = {0};
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		int j = i;	
		while(j)
		{
			count[j % 10]++;
			j /= 10;
		}
	}
	for(i = 0; i < 10; i++)
	{		
		printf("%d\n",count[i]);
	}
	
	return 0;
}
