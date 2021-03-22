
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
 
bool cmp(string a, string b) {
	return a+b < b+a; //按字典序从小到大排列 
}
 
int main() {
	string s[3];
	s[0] = "b"; s[1] = "ba"; s[2] = "ab";
	sort(s, s + 3, cmp);
	string res = "";
	for (int i = 0; i <3; i++)
	{
		res += s[i];
	}
	cout << res << endl;;
	system("pause");
	return 0;
}
