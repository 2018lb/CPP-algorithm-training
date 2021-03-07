#include <iostream>
#include <algorithm>
using namespace std;

long long aa[25];

void change(int k1, int k2, int k3, int k4, long long arr[]){
    long long temp = arr[k1];
    arr[k1] = arr[k2];
    arr[k2] = arr[k3];
    arr[k3] = arr[k4];
    arr[k4] = temp;
}

long long sum(long long arr[]){
    return arr[0]*arr[1]*arr[2]*arr[3]+
    arr[4]*arr[5]*arr[10]*arr[11]+
    arr[6]*arr[7]*arr[12]*arr[13]+
    arr[8]*arr[9]*arr[14]*arr[15]+
    arr[16]*arr[17]*arr[18]*arr[19]+
    arr[20]*arr[21]*arr[22]*arr[23];
}

long long ans = -2e12;
void dfs(int d, long long a[]){
    ans = max(ans, sum(a));
    if (d == 0) return;

    long long arr[25];
    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(1,7,17,21,arr);
    change(3,13,19,23,arr);
    change(8,14,15,9,arr);
    dfs(d-1, arr);


    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(0,6,16,20,arr);
    change(2,12,18,22,arr);
    change(11,10,4,5,arr);
    dfs(d-1, arr);

    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(4,6,8,23,arr);
    change(5,7,9,22,arr);
    change(0,2,3,1,arr);
    dfs(d-1, arr);


    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(10,12,14,21,arr);
    change(11,13,15,20,arr);
    change(16,17,19,18,arr);
    dfs(d-1, arr);

    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(5,3,14,16,arr);
    change(11,2,8,17,arr);
    change(6,7,13,12,arr);
    dfs(d-1, arr);

    for (int i = 0; i < 24; i++){
        arr[i] = a[i];
    }
    change(0,9,19,10,arr);
    change(1,15,18,4,arr);
    change(21,20,22,23,arr);
    dfs(d-1, arr);

}

int main(){
    ios::sync_with_stdio(false);
    long long k[25];
    for (int i = 0; i < 24; i++){
        cin >> k[i];
    }

    dfs(5, k);

    cout << ans;
    return 0;
}
