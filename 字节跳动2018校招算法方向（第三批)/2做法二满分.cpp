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

bool is_ok(int cnt_x, int cnt_y){
    return !(cnt_x < 0 || cnt_x >= n || cnt_y < 0 || cnt_y >= m || map[cnt_x][cnt_y]);
}


ss que_box[6250000];
int Count_tot[6250000];
ss op[500000];
int box_min[51][51][51][51], mark[51][51][51][51];
int dfs_box(ss b, ss e){

    memset(box_min, 0x3f, sizeof(box_min));
    memset(que_box, sizeof(que_box), 0);
    int h = 0, t = 0;
    que_box[0] = b;
    op[0] = start;
    mark[start.x][start.y][b.x][b.y] = 1;
    while (h <= t){
        for (int i = 0; i < 4; i++){
            int cnt_x = op[h].x + x_[i];
            int cnt_y = op[h].y + y_[i];

            int box_x = que_box[h].x + x_[i];
            int box_y = que_box[h].y + y_[i];

            if (is_ok(cnt_x,cnt_y) && (cnt_x != que_box[h].x || cnt_y != que_box[h].y) && !mark[cnt_x][cnt_y][que_box[h].x][que_box[h].y]){

                Count_tot[++t] = Count_tot[h]+1;

                mark[cnt_x][cnt_y][que_box[h].x][que_box[h].y] = 1;

                que_box[t].x = que_box[h].x, que_box[t].y = que_box[h].y;
                op[t].x = cnt_x, op[t].y = cnt_y;

            }

            if (is_ok(box_x,box_y) && cnt_x == que_box[h].x && cnt_y == que_box[h].y && !mark[cnt_x][cnt_y][box_x][box_y]){

                mark[cnt_x][cnt_y][box_x][box_y] = 1;
                Count_tot[++t] = Count_tot[h]+1;
                if (box_x == e.x && box_y == e.y){
                    return Count_tot[t];
                }

                que_box[t].x = box_x, que_box[t].y = box_y;
                op[t].x = cnt_x, op[t].y = cnt_y;
            }
        }
        h++;
    }
    return -1;
}


int main(){
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

    cout <<  dfs_box(box, End);
    return 0 ;
}
