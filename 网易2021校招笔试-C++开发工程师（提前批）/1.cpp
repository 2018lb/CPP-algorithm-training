//
// Created by 78136 on 2021/3/11.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int ans = 2e9;
int a[20];


void dfs(int n, int l, int r, int sum, int cnt){
    if (cnt == n){
        if (l==r) ans = min(ans, sum);
        return;
    }
    dfs(n,l+a[cnt],r,sum,cnt+1);
    dfs(n,l,r+a[cnt],sum,cnt+1);
    dfs(n,l,r,sum+a[cnt],cnt+1);
}


int main(void){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        ans = 2e9;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        dfs(n,0,0,0,0);
        cout << ans << endl;
    }
    return 0;
}