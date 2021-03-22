#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dp[1000];
int cost[1000];
int value[1000];
int main() {
	int n,k;
	cin>>k>>n;
	for(int i=1; i<=n; i++) {
		cin>>cost[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>value[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=cost[i]; j<=k; j++) {
			dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
		}
	}
	cout<<dp[k];
	return 0;
}
