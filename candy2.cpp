#include<iostream>
#include<vector>
int x[100000];
using namespace std;
 
int candy(vector<int> &a){
     int len = a.size();
   if(len == 0||len == 1)
   return len;
   int sum = 0;
   int *candys = new int[len];
   candys[0] = 1;
   for(int i  =1;i < len; i++)
   {
     if(a[i]>a[i-1])
      candys[i] = candys[i-1] + 1;
     else 
      candys[i] = 1;
   }
   sum = candys[len-1];
   for(int i = len-2;i >= 0; i--)
   {
      if( a[i] > a[i+1] && ( candys[i+1]+1 >= candys[i] ))
      candys[i] = candys[i+1] + 1;
      sum += candys[i];
   }
   return sum;
}
 
int main()
{
  int n;
  cin>>n;
  for(int i = 0;i < n; i++) 
      cin>>x[i];
  vector<int> c(x,x+n);  
  cout<<candy(c)<<endl;
 
}
