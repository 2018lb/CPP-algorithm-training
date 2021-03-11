#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int a[2100], b[2100];

int dp[2100][2];

int main(void){
    ios::sync_with_stdio(true);
    int t;
    cin >> t;
    while (t--){
        memset(dp, 0x3f, sizeof(dp));
        int n;
         cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n-1; i++) scanf("%d", &b[i]);

        dp[1][0] = a[1];
        dp[0][0] = dp[0][1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
            dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + b[i-1];
        }

        int ans = min(dp[n][0], dp[n][1]);

        int add_s = ans % 60, add_h = 8 + ans/3600, add_m = (ans%3600) / 60;

        if (add_h < 10) printf("0");
        printf("%d:", add_h);

        if (add_m < 10) printf("0");
        printf("%d:", add_m);

        if (add_s < 10) printf("0");
        printf("%d ", add_s);

        if (add_h > 12) printf("pm\n");
        else printf("am\n");
    }
}
