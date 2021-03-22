#include<iostream>
#include<malloc.h>
using namespace std;
 
void merge(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));
    int i = start;   
    int j = mid + 1;     
    int k = 0;    
 
    while(i <= mid && j <= end)
    {
        if (a[i] >= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
 
    while(i <= mid)
        tmp[k++] = a[i++];
 
    while(j <= end)
        tmp[k++] = a[j++];
 
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];
 
    free(tmp);
};
void mergeSort(int a[], int start, int end)
{
    if(a==NULL || start >= end)
        return ;
 
    int mid = (end + start)/2;
 
    mergeSort(a, start, mid); 
    mergeSort(a, mid+1, end); 
 
    merge(a, start, mid, end);
};

int main()
{
	int n1,n;
	int a[100];    //int型数组用于存储输入变量
    int i = 0;
    while(scanf("%d",&n1)!=EOF){ 
    for(i = 0; i < n1; i++)
    {
       cin >> a[i];
    }
	mergeSort(a,0,n1-1);
	for(i = 0 ; i < n1 ; i++)
	{
	   if(i == n1-1)
	   cout << a[i];
	   else
	   cout << a[i] << ' ';
	}
	printf("\n");
	} 
}
