#include<stdio.h>
#include<math.h>
int q(int n) {
	int i;
	int sum = 0;
	for(i = 2; i < n; i++) {
		if(n % i == 0) {
			sum++;
			sum+=q(n/i);
		}
	}
	return sum;
}
int main() {
	int n;
	scanf("%d",&n);
	printf("%d",q(n)+1);
}
