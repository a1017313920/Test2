#include <iostream>
#include<stdlib.h>
using namespace std;

int *list;    //����������
int n;        //����������Ԫ�ظ���

void Backtrack(int t) {
	if(t>n) {
		for (int i = 1; i <= n ; i++)
			cout<<list[i];
		cout<<endl;
	} 
	else {
		for (int i = t; i <= n ; i++) {
			swap(list[t],list[i]);
			Backtrack(t+1);
			swap(list[t],list[i]);
		}
	}
}
int main() {
	cin>>n;
	list=(int*)malloc(sizeof(int)*(n+1));
	for (int i = 1; i <=n ; i++)
		cin>>list[i];
	Backtrack(1);
}
