#include<iostream>
using namespace std;
void Swap(int & a, int &b)//��������ֵ
{
	int temp = a;
	a = b;
	b = temp;
}
void BackTrack(int list[], int k, int m)//����list[k��m]���������У��ӵ�kλ����mλ����
{
	if (k == m) //ֻʣ��һ��Ԫ�أ��ݹ����
	{
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	}	
	else //���ж��Ԫ�ش����У��ݹ��������
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
