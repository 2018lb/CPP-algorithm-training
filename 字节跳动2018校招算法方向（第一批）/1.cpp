#include <iostream>
#include <algorithm>

struct poi
{
    int x, y;
}a[500010];

bool com(poi a, poi b)
{
    return a.y > b.y || (a.y == b.y && a.x > b.x);
}

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a,a+n,com);

    int max_X = a[0].x;
    cout << a[0].x << ' ' << a[0].y << endl;
    for (int i = 1; i < n; i++){
        if (a[i].x > max_X){
            cout << a[i].x << ' ' << a[i].y << endl;
            max_X = a[i].x;
        }
    }

    return 0;
}
