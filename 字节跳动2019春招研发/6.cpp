#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n, tot = 0;
    cin >> n;
    n = 1024-n;

    while (n >= 64){
        tot++;
        n -= 64;
    }

    while (n >= 16){
        tot++;
        n -= 16;
    }

    while (n >= 4){
        tot++;
        n -= 4;
    }

    tot += n;

    cout << tot;
    return 0;
}