#include <iostream>

using namespace std;

void move(char a, char b) {

	cout<<a<<"----->"<<b<<endl;
}

void hannuo(int n, char a, char b, char c , char d) {

	if(1==n) {

		move(a, d);
	}

	else if(2 == n) {

		move(a, b);

		move(a, d);

		move(b, d);
	}

if(n>2){
		hannuo(n-2, a, c, d, b);

		move(a,c);

		move(a,d);

		move(c,d);

		hannuo(n-2, b, a, c, d);
	}
}

int main() {

	char a='a', b='b', c='c', d = 'd';

	int i;

	cout<<"请输入盘子的个数";

	while (cin>>i) {

		hannuo(i, a, b, c, d);

		return 0;
	}
}
