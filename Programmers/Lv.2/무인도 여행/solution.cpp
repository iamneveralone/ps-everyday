#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int visited[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, area;

void dfs(vector<string> maps, int x, int y){
    visited[x][y] = true;
    area += (maps[x][y] - '0');
    
    for (int k = 0; k < 4; k++){
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];
        
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[nx][ny]) continue;
        if (maps[nx][ny] == 'X') continue;
        
        dfs(maps, nx, ny);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> ans;
    n = maps.size(); m = maps[0].length();
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maps[i][j] != 'X' && !visited[i][j]){
                dfs(maps, i, j);
                ans.push_back(area);
                area = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    if (ans.size() == 0) ans.push_back(-1);
    return ans;
}