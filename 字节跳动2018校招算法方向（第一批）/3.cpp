#include <iostream>
#include <algorithm>
#include <queue>
struct PM_poi
{
    int PM, start, lv, tim, num;
    bool operator < (const PM_poi &t) const{
        if (this->lv < t.lv) return true;
        if (this->lv > t.lv) return false;

        if (this->tim > t.tim) return true;
        if (this->tim < t.tim) return false;

        // (this->PM > t.PM) return true;
        //if (this->PM < t.PM) return false;

        if (this->start > t.start) return true;
        if (this->start < t.start) return false;

        return false;
    }
}a[3010];

int T_[30000];

bool com(PM_poi a, PM_poi b){
    return a.start < b.start;
}

int ans[3050];
using namespace std;

priority_queue<PM_poi, vector<PM_poi>, less<PM_poi>> que[5000];

int main(){
    ios::sync_with_stdio(false);
    int n,m,p;
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++){
        cin >> a[i].PM >> a[i].start >> a[i].lv >> a[i].tim;
        a[i].num = i;
    }

    sort(a,a+p,com);

    int fin = 0, set = m, t = 0, num = 0, now = 0;
    while (fin != p){
        t++;
        while (t == a[num].start){
            que[a[num].PM].push(a[num++]);
            now++;
        }
        set += T_[t];
        while (set && now){
            PM_poi cnt_test;
            int mark = 0, tim = 50000;
            for (int pm = 1; pm <= n; pm++){
                if (!que[pm].empty()){
                    cnt_test = que[pm].top();
                    if (cnt_test.tim < tim){
                        tim = cnt_test.tim;
                        mark = pm;
                    }
                }
            }
            now--; set--;

            cnt_test = que[mark].top();
            T_[t+cnt_test.tim]++;
            ans[cnt_test.num] = t+cnt_test.tim;
            que[mark].pop();
            fin++;
        }
    }

    for (int i = 0; i < p; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
