#include <iostream>
#include<stdlib.h>
using namespace std;

int n;          //��װ������
int w[3500];    //��װ����������
int c;          //��һ���ִ���������
int cw = 0;       //��ǰ������
int bestw = 0;    //��ǰ����������
int r = 0;        //ʣ�༯װ������
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
