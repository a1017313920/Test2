#include<stdio.h>
#include<math.h>
float min;
int n;
float x[1000];
float r[1000];
void Swap(int*p1,int*p2){
	*p1=a;*p2=b;
}
float Center(int t)
{
	float temp = 0;
	int j;
	for(j=1;j<t;j++){
		float valuex = x[j] + 2.0*sqrt(r[t] * r[j]);
		if(valuex > temp)
		  temp = valuex;
	}
}
void Compute()
{
	float low = 0,high = 0;
	int i;
	for(i=1; i <=n;i++){
		if(x[i]-r[i] < low)
		   low = x[i]-r[i];
		if(x[i]+r[i] > high)
		   high = x[i] + r[i];
	}
	if(high-low < min)
	   min = high - low;
}
void Bcaktrack(int t)
{
	if(t > n)
	   Compute();
	else{
		int j;
		for(j=t; j <= n; j++){
			Swap(r[t],r[j]);
			float centerx = Center(t);
			if(centerx + r[t] + r[1] < min){
				x[t] = centerx;
				Backtrack(t+1);
			}
			Swap(r[t],r[j]);
		}
	}
}
