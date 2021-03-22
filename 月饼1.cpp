#include <iostream>
#include <vector>
#include <algorithm>
 
#define MAX 1000 + 10
 
using namespace std;
 
typedef struct {
    double weight;
    double value;
    double price;
} Bing;
 
Bing bing[MAX];
 
int cmp( Bing a, Bing b ) {
    return a.price > b.price;
}
 
int main() {
    int n;
    int m;
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) {
        cin >> bing[i].weight;
    }
 
    for ( int i = 0; i < n; i++ ) {
        cin >> bing[i].value;
        bing[i].price = bing[i].value / bing[i].weight;
    }
 
    sort( bing, bing + n, cmp );
 
    int now_weight = 0;
    double sum = 0.0;
    int index = 0;
    while ( now_weight < m && index < n ) {
        if ( m >= bing[index].weight ) {
            m = m - bing[index].weight;
            sum = sum + bing[index].value;
        }
        else {
            sum = sum + m * bing[index].price;
            m = 0;
        }
        index++;
    }
 
    printf( "%.2lf", sum );
    return 0;
}
