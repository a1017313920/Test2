
#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

map<int, int> a;

int f(int n) {

    if (a[n]) {
        return  a[n];
    }

    int Count = 1; // x  = x 
    for (int i = 2; i <= sqrt(n); i++) {
        // ��� x = j*k ���Էֽ⣬������ӽ� [j]��
        if (n % i == 0) {
            Count += f(i);
            // ��� j!=k��������ӽ�k
            if (i != n / i) {
                Count += f(n / i);
            }
        }

    }

    a[n] = Count; // ��¼�������У�Ϊ֮���ʹ��
    return Count;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
}
