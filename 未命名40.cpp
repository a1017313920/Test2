// 动态规划求解并输出所有LCS
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

char x[100];
char y[100];
//string x = "ABC";
//string y = "D";
vector<vector< int> > table; // 动态规划表
set<string> setOflcs;      // set保存所有的LCS

/**
 * 构造表，并返回X和Y的LCS的长度
 */
int lcs(int m, int n)
{
    int biggest = 0;
    // 表的大小为(m+1)*(n+1)
    table = vector<vector<int> >(m+1, vector<int>(n+1));
    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            // 第一行和第一列置0
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if(x[i-1] == y[j-1])
            {
		            table[i][j] = table[i-1][j-1] + 1;
		            if(table[i][j] > biggest)
                       biggest = table[i][j]; // 存放LCS的长度
	    }
	    else
		table[i][j] = 0;
        }
    }
    return biggest;
}

/**
 * 求出所有的最长公共子串，并放入set中
 */
void traceBack(int m, int n, int lcs_len)
{
    string strOflcs;
    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            // 查到等于lcs_len的值，取字符
            if(table[i][j] == lcs_len)
            {
                int ii = i, jj = j;
                while(table[ii][jj] >= 1)
                {
                    strOflcs.push_back(x[ii-1]);
                    ii--;
                    jj--;
                }
                string str(strOflcs.rbegin(), strOflcs.rend()); // strOflcs逆序
                if((int)str.size() == lcs_len)                       // 判断str的长度是否等于lcs_len
                {
                    setOflcs.insert(str);
                    strOflcs.clear();                           // 清空strOflcs
                }
            }
        }
    }
}

// 输出set
void print()
{
    set<string>::iterator iter = setOflcs.begin();
    for(; iter != setOflcs.end(); iter++)
        cout << *iter << endl;
}

int main()
{
	string a;
	string b;
	
    int m = ;
    int n = ;
   // string x(&a[0],&a[m]);
   // string y(&b[0],&a[n]);
    int res = lcs(m, n);
    cout << "res = " << res << endl;
    if(res == 0)
       cout<<"NO";
    traceBack(m, n, res);
    print();
    //getchar();
    return 0;
}
