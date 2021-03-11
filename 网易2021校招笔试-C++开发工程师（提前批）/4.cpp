#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
//https://ac.nowcoder.com/question/next?pid=28083344&qid=1272746&tid=41875770
/*int DFN[1000000], low[1000000];
bool mark[1000000];
int start[1000000];
int num[1000000], sum = 0;


stack<int> s;

struct edge{
    int x, y, next;
}E[1000000];
int tot_E = 0;

int inx = 0;
void tarjan(int i){
    DFN[i] = low[i] = inx++;
    mark[i] = 1;
    s.push(i);
    for (int j = start[i]; j; j = E[j].next){
        if (!DFN[E[j].y]){
            tarjan(E[j].y);
            low[i] = min(low[i], low[E[j].y]);
        }else{
            if (mark[E[j].y]) low[i] = min(low[i], low[E[j].y]);
        }
    }

    if (DFN[i] == low[i]){
        int k;
        do {
            k = s.top();
            mark[k] = 0;
            s.pop();
            num[sum]++;
        }while (k!=i);
        sum++;
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        E[++tot_E].x = x;
        E[tot_E].y = y;
        E[tot_E].next = start[x];
        start[x] = tot_E;
    }

    for (int i = 1; i <= n; i++){
        if (!DFN[i]){
            tarjan(i);
        }
    }

    long long ans = 0;
    for (int i = 0; i < sum; i++){
        long long kl = num[i];
        ans +=( kl*kl - kl) / 2;
    }

    cout << ans;
    return 0;
}
*/