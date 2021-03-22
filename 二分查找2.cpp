#include<iostream>
using namespace std;
int i=0, j=0;
void binSearch(int arr[], int x, int left, int right)
{
    int mid = (left + right)/2;
    if(left>right) return;
    if(x == arr[mid]){
        i = j = mid;
    }
    if(x > arr[mid]){
        i = mid;
        left = mid + 1;
        binSearch(arr, x, left, right);
    }else{
        j = mid;
        right = mid - 1;
        binSearch(arr, x, left, right);
    }
 }
int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(x>arr[n-1]){
        i = n-1;
        j = n;
    }else if(x<arr[0]){
        i = -1;
        j = 0;
    }
    binSearch(arr, x, 0, n-1);
    cout<<i<<" "<<j;
    return 0;
}

 
