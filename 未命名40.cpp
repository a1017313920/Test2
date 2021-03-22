// ��̬�滮��Ⲣ�������LCS
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
vector<vector< int> > table; // ��̬�滮��
set<string> setOflcs;      // set�������е�LCS

/**
 * �����������X��Y��LCS�ĳ���
 */
int lcs(int m, int n)
{
    int biggest = 0;
    // ��Ĵ�СΪ(m+1)*(n+1)
    table = vector<vector<int> >(m+1, vector<int>(n+1));
    for(int i = 0; i < m+1; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            // ��һ�к͵�һ����0
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else if(x[i-1] == y[j-1])
            {
		            table[i][j] = table[i-1][j-1] + 1;
		            if(table[i][j] > biggest)
                       biggest = table[i][j]; // ���LCS�ĳ���
	    }
	    else
		table[i][j] = 0;
        }
    }
    return biggest;
}

/**
 * ������е�������Ӵ���������set��
 */
void traceBack(int m, int n, int lcs_len)
{
    string strOflcs;
    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            // �鵽����lcs_len��ֵ��ȡ�ַ�
            if(table[i][j] == lcs_len)
            {
                int ii = i, jj = j;
                while(table[ii][jj] >= 1)
                {
                    strOflcs.push_back(x[ii-1]);
                    ii--;
                    jj--;
                }
                string str(strOflcs.rbegin(), strOflcs.rend()); // strOflcs����
                if((int)str.size() == lcs_len)                       // �ж�str�ĳ����Ƿ����lcs_len
                {
                    setOflcs.insert(str);
                    strOflcs.clear();                           // ���strOflcs
                }
            }
        }
    }
}

// ���set
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
