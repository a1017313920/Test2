#include<iostream>
#include<vector>
#include<numeric>
int x[100000];
using namespace std;
 
int candy(int* a, int n){
    int len[n], sum = 0;
    len[0] = 1;
    for(int i = 1; i < n; i++)
        if(a[i] > a[i - 1])
            len[i] = len[i-1] + 1;
        else
            len[i] = 1;

    for(int j = n - 2; j >= 0; j--)
        if(a[j] > a[j + 1])
            if(len[j] <= len[j+1])
                len[j] = len[j+1] + 1;

    for(int i = 0; i < n; i++)
        sum += len[i];
    return sum;
}
int main()
{
  int n;
  cin>>n;
  for(int i = 0;i < n; i++) 
      cin>>x[i];
  cout<<candy(x,n)<<endl;
 
}
