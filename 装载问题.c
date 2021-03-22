#include <iostream>
#include<stdlib.h>
using namespace std;

int n;          //集装箱数量
int w[3500];    //集装箱重量数组
int c;          //第一艘轮船的载重量
int cw = 0;       //当前载重量
int bestw = 0;    //当前最优载重量
int r = 0;        //剩余集装箱重量
int bestx[3500];
int h=0;

int barktrack(int i) {
    
    if (i > n) {
        h = n;
        bestw = cw;
        return 0;
    }
    
    r -= w[i];
    if (cw + w[i] <= c) {
        cw += w[i];
        barktrack(i + 1);
        cw -= w[i];
        if (h == i) {
            bestx[i] = 1;
            h--;
        }
    }
    
    if (cw + r > bestw) {
        barktrack(i + 1);
        if (h == i) {
            bestx[i] = 0;
            h--;
        }
    }
    r += w[i];
    return 1;
}

int main() {
    cin>>n>>c;
    for (int i = 1; i <= n; i++) {
        cin>>w[i];
        r += w[i];
    }
    barktrack(1);
    cout<<bestw;
    
    for (int i = 1; i <= n; i++) {
        cout<<bestx[i];
    }
}
