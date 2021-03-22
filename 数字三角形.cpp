#include<iostream>
using namespace std;

int a[100][100] = {0};
int dp[100][100] = {0};

int main(){
    int n;
    cin>>n;
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= i; j++ )
            cin>>a[i][j];
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= i; j++ )
            dp[i][j] = a[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
    int ans = 0;
    for( int j = 1; j <= n; j++ )
        ans = max(ans,dp[n][j]);
    cout<<ans<<endl;
    return 0;
}
