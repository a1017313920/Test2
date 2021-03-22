#include<stdio.h>
#include<math.h>
int q(int n) {
	int i;
    if(n == 1) 
	  return 1;
    int cnt = 1;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == sqrt(n)) 
                cnt += q(i);
            else 
                cnt += q(n / i) + q(i);
        }
    }
    return cnt;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",q(n));
}
