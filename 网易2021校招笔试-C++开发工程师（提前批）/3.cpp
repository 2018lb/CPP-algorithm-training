//
// Created by 78136 on 2021/3/11.
//小易爱回文

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

char s[100000];
int n;

bool pd_0(int x){
    int i = x, j = x+1;
    while (1){
        if (s[i]!=s[j]) return false;
        if (j >= n - 1) return true;
        i--, j++;
    }
}

bool pd_1(int x){
    int i = x-1, j = x+1;
    while (1){
        if (s[i]!=s[j]) return false;
        if (j >= n - 1) return true;
        i--, j++;
    }
}

int main(void){
    scanf("%s", s);
    n = strlen(s);
    int ans = n-1, mark = 1;
    for (int k = n-2; k >= n/2-1; k--){
        if(pd_0(k)) ans = k, mark = 0;
        if(pd_1(k)) ans = k, mark = 1;
    }

    printf("%s", s);
    int i = 2*ans - mark - n +1;
    for (; i >= 0; i--){
        printf("%c", s[i]);
    }
    return 0;
}


