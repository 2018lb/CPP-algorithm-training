#include <iostream>
#include <algorithm>

int a[500010];
int num[101];

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        num[a[i]]++;
    }

    int max_ans = 0;
    for (int k = 0; k <= 100; k++){
        if (num[k] == 0) continue;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++){
            if (a[i] < k){
                ans = max(ans, cnt*k);
                cnt = 0;
                continue;
            }
            cnt += a[i];
        }
        max_ans = max(max_ans, ans);
    }
    cout << max_ans;

    return 0;
}
