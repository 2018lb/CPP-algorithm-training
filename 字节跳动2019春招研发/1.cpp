#include <iostream>
#include <cstring>
using namespace std;

char s[1000];
int main() {
    ios::sync_with_stdio(true);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s;
        int len = strlen(s), mark = 0, k = 0;
        for (int j = 2; j < len; j++){
            int cnt = j-1;
            while (s[cnt] == '0' && cnt >0){
                cnt--;
            }
            int k1 = cnt;

            cnt--;
            while (s[cnt] == '0' && cnt >=0){
                cnt--;
            }
            if (cnt < 0) continue;
            int k2 = cnt;
            if (s[j] == s[k1] && s[k1] == s[k2])  s[j] = '0';

            cnt--;
            while (s[cnt] == '0' && cnt >0){
                cnt--;
            }
            if (cnt < 0) continue;
            int k3 = cnt;
            if (s[j] == s[k1] && s[k2] == s[k3])  s[j] = '0';
        }
        for (int j = 0; j < len; j++)
            if (s[j] != '0')
                cout << s[j];

            cout << endl;
    }
    return 0;
}
