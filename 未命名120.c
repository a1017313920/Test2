//  main.c
//  ph
//
//  Created by zsk on 2020/10/21.
//

#include <stdio.h>
void Swap(int *target, int *current){
    int p = *target;
    *target = *current;
    *current = p;
}


void QuickSort(int *arr, int left, int right){
    if(left > right)
    {
        return;
    }
    int temp = arr[left];
    int i = left;
    int j = right;
    while(i < j)
    {
        while(arr[j] >= temp && i < j)
        {
            j--;
        }
        while(arr[i] <= temp && i < j)
        {
            i++;
        }
        if(i < j){
            Swap(&arr[i], &arr[j]);
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    QuickSort(arr, left, i - 1);
    QuickSort(arr, i + 1, right);
    return ;
}


int main(){
    int i;
    int a;
    scanf("%d",&a);
    int arr[100] ;
    for(i = 0; i < a; i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr, 0, a - 1);
    
    for(i = 0; i <a; i++)
    {
        if(i==a-1)
            printf("%d",arr[i]);
        if(i<a-1)
            printf("%d ", arr[i]);
    }
   return  0;
}
