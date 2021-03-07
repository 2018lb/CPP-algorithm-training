#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct ss{
    int x, y;
}start, box, End;

bool map[100][100];


const int x_[4] = {0,1,0,-1};
const int y_[4] = {1,0,-1,0};
int n, m;

ss que1[500000];
int Count[500000];
bool mark[100][100];
int dfs(ss b, ss e, ss BBox){
    memset(que1, 0, sizeof(que1));
    memset(Count, 0, sizeof(Count));
    memset(mark, 0, sizeof(mark));
    map[BBox.x][BBox.y] = 1;
    int h = 0, t = 0;
    que1[0] = b;
    while (h <= t){
        for (int i = 0; i < 4; i++){
            int cnt_x = que1[h].x + x_[i];
            int cnt_y = que1[h].y + y_[i];
            if (cnt_x < 0 || cnt_x >= n || cnt_y < 0 || cnt_y >= m || map[cnt_x][cnt_y] || mark[cnt_x][cnt_y]) continue;

            mark[cnt_x][cnt_y] = 1;
            que1[++t].x = cnt_x;
            que1[t].y = cnt_y;
            Count[t] = Count[h] + 1;
            if (cnt_x == e.x && cnt_y == e.y)  return Count[t];
        }
        h++;
    }
    return -1;
}


ss que_box[500000];
int Count_tot[500000];
ss op[500000];
int box_min[100][100];
int dfs_box(ss b, ss e){
    int min_ans = 1000000;
    memset(box_min, 0x3f, sizeof(box_min));
    memset(que_box, sizeof(que_box), 0);
    int h = 0, t = 0;
    que_box[0] = b;
    op[0] = start;
    while (h <= t){
        for (int i = 0; i < 4; i++){
            int cnt_x = que_box[h].x + x_[i];
            int cnt_y = que_box[h].y + y_[i];

            int op_x = que_box[h].x - x_[i];
            int op_y = que_box[h].y - y_[i];

            if (cnt_x < 0 || cnt_x >= n || cnt_y < 0 || cnt_y >= m || map[cnt_x][cnt_y]) continue;
            if (op_x < 0 || op_x >= n || op_y < 0 || op_y >= m || map[op_x][op_y]) continue;

            ss op_ss;
            op_ss.x = op_x, op_ss.y = op_y;
            int sum = dfs(op[h], op_ss, que_box[h]);
            map[que_box[h].x][que_box[h].y] = 0;



            if (sum == -1 || sum + Count_tot[h] >= box_min[cnt_x][cnt_y]) continue;

            box_min[cnt_x][cnt_y] = sum + Count_tot[h];
            que_box[++t].x = cnt_x;
            que_box[t].y = cnt_y;
            op[t] = op_ss;
            Count_tot[t] = Count_tot[h] + sum;
            if (cnt_x == e.x && cnt_y == e.y) {
                min_ans = min(min_ans, Count_tot[t]);
            }
        }
        h++;
    }
    return min_ans;
}


int main2(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    char ss[60];
    for (int i = 0; i < n; i++){
        cin >> ss;
        for (int j = 0; j < m; j++){
            if (ss[j] == '#')
                map[i][j] = 1;
            if (ss[j] == 'S')
                start.x = i, start.y = j;
            if (ss[j] == '0')
                box.x = i, box.y = j;
            if (ss[j] == 'E')
                End.x = i, End.y = j;
        }
    }

    int ans = dfs_box(box, End);
    if (ans == 1000000) cout << -1;
    else cout << ans+1;
    return 0 ;
}
