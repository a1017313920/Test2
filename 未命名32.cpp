#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_N = 100;
string a, b;
int dp[MAX_N][MAX_N];
int main()
{
    memset(dp, 0, sizeof(dp));
    int cnt = 0;
    vector<int> ans;
    cin >> a >> b;
    for (int i = 1; i < a.size() + 1; i++)
    {
        for (int j = 1; j < b.size() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (cnt < dp[i][j])
                {
                    cnt = dp[i][j];
                    ans.clear();
                    ans.push_back(i);
                    //cout << "insert " << i << " and cnt = " <<cnt  <<endl;
                }
                else if (cnt == dp[i][j])
                {
                    ans.push_back(i);
                    //cout << "insert " << i <<endl;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    vector<int>::iterator it;
    vector<string> res;
    for (it = ans.begin(); it != ans.end(); it++)
    {
    	cout << *it;
        string s;
        for (int i = *it - cnt; i < *it; i++)
        {
            s += a[i];
        }
        res.push_back(s);
    }
    if (cnt == 0)
        cout << "NO\n";
    else
    {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
    }

    return 0;
}
