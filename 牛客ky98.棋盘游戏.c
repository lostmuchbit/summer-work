#include <stdio.h>
#define mapSize 6
int map[mapSize + 1][mapSize + 1];
int vis[mapSize + 1][mapSize + 1];
int a, b, c, d;
int ans = 99999999;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
  
int min(int a, int b) {
    return a < b ? a : b;
}
  
void dfs(int x, int y, int curCost, int curStatus) {
    if (x == c + 1 && y == d + 1) {
        ans = min(ans, curCost);
        return;
    }
    if (curCost > ans) {
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 1 || tx > 6 || ty < 1 || ty > 6 || vis[tx][ty] == 1) {
            continue;
        }
        int cost = map[tx][ty] * curStatus;
        int newStatus = (cost % 4) + 1;
        dfs(tx, ty, curCost + cost, newStatus);
    }
    vis[x][y] = 0;
}
  
int main() {
    for (int i = 1; i <= mapSize; ++i) {
        for (int j = 1; j <= mapSize; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d%d%d%d", &a, &b, &c, &d);
    dfs(a + 1, b + 1, 0, 1);
    printf("%d\n", ans);
    return 0;
}
