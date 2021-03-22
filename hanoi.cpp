#include<iostream>
#include<string>
using namespace std;
int n;
void hanoi(int n,char a,char b,char c){
 if(n==1){
  printf("%d %c %c\n",1,a,c);
 }
 else{
  hanoi(n-1,a,c,b);
  printf("%d %c %c\n",n,a,c);
  hanoi(n-1,b,a,c);
 }
}
int main(){
 scanf("%d",&n);
 hanoi(n,'A','C','B');
 return 0;
}
