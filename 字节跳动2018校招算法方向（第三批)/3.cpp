#include <iostream>
#include <algorithm>
using namespace std;

long long a[100100];

int main(){
    ios::sync_with_stdio(false);
    long long n, x, min_num = 1e9+10;
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        min_num = min(min_num, a[i]);
    }

    for (int i = 0; i < n; i++){
        a[i] -= min_num;
    }

    int k = x - 1, sum = 0;
    while(a[k] != 0){
        sum++;
        --a[k--];
        if (k < 0) k = n - 1;
    }
    a[k] = min_num * n + sum;

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}
