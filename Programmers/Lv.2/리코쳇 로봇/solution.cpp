#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int visited[101][101];
int n, m;

void bfs(vector<string> board, int sx, int sy){
    visited[sx][sy] = 0;
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++){
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 'D') continue;
            
            // 맨 끝 or 장애물 만날 때까지 같은 방향으로 미끄러져 이동
            while(nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] != 'D'){
                nx += dir[k][0];
                ny += dir[k][1];
            }
        
            // (nx, ny) := 맨 끝 or 장애물 위치 직전의 위치
            nx -= dir[k][0];
            ny -= dir[k][1];
            
            // 방문한 곳은 pass
            if (visited[nx][ny] >= 0) continue;
            
            visited[nx][ny] = visited[x][y] + 1;
            
            q.push({nx, ny});
        }

    }
}

int solution(vector<string> board) {

    pair<int, int> start, end;
    n = board.size();
    m = board[0].length();
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            visited[i][j] = -1;
            
            if (board[i][j] == 'R'){
                start = {i, j};
            }
            if (board[i][j] == 'G'){
                end = {i, j};
            }
        }
    }
    
    bfs(board, start.first, start.second);
    
    if (visited[end.first][end.second] == -1) return -1;
    else return visited[end.first][end.second];
}