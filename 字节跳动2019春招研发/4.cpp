
#include <iostream>
#include <algorithm>
#include "cstring"
#include <map>
using namespace std;

struct ss{
    int last = -10, tot = 1;
};

struct poi{
    int x, y;
    bool operator<(const poi& a) const{
        return (this->x < a.x)||(this->x == a.x && this->y < a.y);
    }
};

map<poi, ss> a;


int main(){
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while (t--){
        int ans = 0;
        cin >> n;
        while (n--){
            int m;
            cin >> m;
            for (int i = 0; i < m; i++){

                poi x;
                cin >> x.x >> x.y;

                if (a[x].last == n+1) a[x].tot++;
                else a[x].tot = 1;

                ans = max(ans, a[x].tot);
                a[x].last = n;
            }
        }
        cout << ans;
    }
    return 0;
}
