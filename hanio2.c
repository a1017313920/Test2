#include<stdio.h>
int n;
void hanoi(int n,char a,char b,char c){
 if(n==1){
  printf("%d %c %c\n",1,a,b);
 }
 else{
  hanoi(n-1,a,c,b);
  printf("%d %c %c\n",n,a,b);
  hanoi(n-1,b,a,c);
 }
}
int main(){
 scanf("%d",&n);
 hanoi(n,'A','B','C');
 printf("%d",(5+6)/2);
 return 0;
}
