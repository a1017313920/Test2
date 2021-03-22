#include <stdio.h>
int main(){
    int n,x;
    int a[100];
    int i;
    scanf("%d",&n);
    scanf("%d",&x);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int left = 0; 
    int right = n-1;
    if(x < a[0]){
        printf("-1 0");
        return 0;
    }
    if(x > a[n-1]){
        printf("%d %d",n-1,n);
        return 0;
    }
    while(left <= right){
        int middle = (left + right) / 2;
        if (x == a[middle]) {
            printf("%d %d",middle,middle);
            return 0;
        }
        else if (x > a[middle]){
            left = middle + 1;
        } 
        else{
            right = middle - 1;    
        }
    }
    printf("%d %d",right,left);
    return 0;
}
