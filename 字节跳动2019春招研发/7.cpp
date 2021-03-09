#include <iostream>
#include <cstring>
using namespace std;
int a[1000000];

bool pd(int k, int n, int max_num){
    for (int i = 0; i < n; i++){
        k += k - a[i];
        if (k >= max_num) return true;
        if (k < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(true);
    int n, max_num = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        max_num = max(max_num, a[i]);
    }

    int l = 0, r = max_num;
    while (l < r){
        int mid = (l+r)/2;
        if (pd(mid, n, max_num)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return 0;
}
