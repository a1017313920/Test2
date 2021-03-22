
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
        // 如果 x = j*k 可以分解，则先添加进 [j]。
        if (n % i == 0) {
            Count += f(i);
            // 如果 j!=k，则再添加进k
            if (i != n / i) {
                Count += f(n / i);
            }
        }

    }

    a[n] = Count; // 记录在数组中，为之后的使用
    return Count;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
}
