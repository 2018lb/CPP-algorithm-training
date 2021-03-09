#include <iostream>
#include <algorithm>
using namespace std;

int map[50][50];

int dp[30][1068576];

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    int statement = 1 << n-1;
    for (int S = 1; S < statement; S++){

        for (int i = 1; i < n; i++){
            if (S & 1 << i-1){

                if (S == 1 << i-1){
                    dp[i][S] = map[0][i];
                }

                else
                {
                    dp[i][S] = 2e9;
                    for (int k = 1; k < n; k++) {
                        if (k == i || !(1<<k-1 & S)) continue;
                        dp[i][S] = min(dp[i][S], dp[k][S - (1<<i-1)] + map[k][i]);
                    }
                }
            }
        }
    }
    int ans = 2e9;
    for (int i = 1; i < n; i++) ans = min(ans, dp[i][statement-1]+ map[i][0]);

    cout << ans;
    return 0;
}
