#include<iostream>
using namespace std;
void Swap(int & a, int &b)//交换变量值
{
	int temp = a;
	a = b;
	b = temp;
}
void BackTrack(int list[], int k, int m)//产生list[k：m]的所有排列，从第k位到第m位排列
{
	if (k == m) //只剩下一个元素，递归结束
	{
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}	
	else //还有多个元素待排列，递归产生排列
	for (int i = k; i <= m; i++)
	{
		Swap(list[k], list[i]);
		BackTrack(list, k + 1, m);
		Swap(list[k], list[i]);
	}
 
}
int main()
{
	int list[] = { 5,6,7,8 };
	BackTrack(list, 0, 3);
	return 0;
}
