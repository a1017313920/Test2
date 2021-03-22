#include <iostream>
#include <math.h>
using namespace std;
const int maxn=100;
int n;
float minx=1000000;
float x[maxn],r[maxn];
float center(int t) {
	float temp=0;
	for(int j=1; j<t; j++) {
		float valuex=x[j]+2.0*sqrt(r[t]*r[j]);
		if(valuex>temp)
			temp=valuex;
	}
	return temp;
}
void compute() {
	float low=0,high=0;
	for(int i=1; i<=n; i++) {
		if(x[i]-r[i]<low)
			low=x[i]-r[i];
		if(x[i]+r[i]>high)
			high=x[i]+r[i];
	}
	if(high-low<minx)
		minx=high-low;
}
void Backtrack(int t) {
	if(t>n)
		compute();
	else {
		for(int j=t; j<=n; j++) {
			swap(r[t],r[j]);
			float c=center(t);
			if(c+r[t]+r[1]<minx) {
				x[t]=c;
				Backtrack(t+1);
			}
			swap(r[t],r[j]);
		}
	}
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>r[i];
	Backtrack(1);
	cout <<minx <<endl;
	return 0;
}
