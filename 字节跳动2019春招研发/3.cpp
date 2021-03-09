//
// Created by 78136 on 2021/3/8.
//

#include <iostream>
#include <algorithm>
#include "cstring"
using namespace std;

bool pd(bool head, int num[], int sum){

    if (sum == 14 && head) return true;

    int k = 0;
    int cnt_num[10];

    for (int i = 1; i <= 9; i++){
        cnt_num[i] = num[i];
        if (k == 0 && num[i] != 0 ) k = i;
    }

    if (cnt_num[k] >= 2 && !head){
        cnt_num[k] -= 2;
        if (pd(true, cnt_num, sum +2)) return true;
        cnt_num[k] += 2;
    }

    if (cnt_num[k] >= 3 ){
        cnt_num[k] -= 3;
        if (pd(head, cnt_num, sum +3)) return true;
        cnt_num[k] += 3;
    }

    if (k <= 7 && cnt_num[k] >= 1 && cnt_num[k+1] >= 1 && cnt_num[k+2] >= 1){
        cnt_num[k] -= 1 , cnt_num[k+1] -= 1 , cnt_num[k+2] -= 1;
        if (pd(head, cnt_num, sum +3)) return true;
        cnt_num[k] += 1 , cnt_num[k+1] += 1 , cnt_num[k+2] += 1;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);

    int num[10];
    memset(num, 0, sizeof(num));

    for (int i = 1; i <=13; i++){
        int x;
        cin >> x;
        num[x]++;
    }

    int ok = 0;
    for (int i = 1; i <= 9; i++){
        if (num[i] == 4 ) continue;
        num[i]++;
        if (pd(false, num, 0)) {
            ok = 1;
            cout << i << ' ';
        }
        num[i]--;
    }

    if (!ok) cout << '0';
    return 0;
}
