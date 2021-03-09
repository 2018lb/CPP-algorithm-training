#include <iostream>
#include <algorithm>
using namespace std;

int road[1000100];

int main(){
    ios::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> road[i];

    }

    long long ans = 0;
    long long h = 0, tot = 1;
    for (int i = 2; i < n; i++){
        tot++;
        while (road[i] - road[h] > d){
            h++;
            tot--;
        }
        if (tot > 0) ans = (ans + ((tot*tot) - tot)/2 ) % 99997867;
    }


    cout << ans;

    return 0;
}
