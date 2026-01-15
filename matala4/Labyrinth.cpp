#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> parent(n, vector<char>(m));
    vector<vector<pair<int,int>>> prev(n, vector<pair<int,int>>(m));

    queue<pair<int,int>> q;
    int sx, sy, ex, ey;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                sx = i;
                sy = j;
            }
            if(grid[i][j] == 'B'){
                ex = i;
                ey = j;
            }
        }
    }

    q.push({sx, sy});
    vis[sx][sy] = true;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    char dir[4] = {'L', 'R', 'U', 'D'};

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!vis[nx][ny] && grid[nx][ny] != '#'){
                    vis[nx][ny] = true;
                    parent[nx][ny] = dir[i];
                    prev[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }

    if(!vis[ex][ey]){
        cout << "NO";
        return 0;
    }

    string path;
    int x = ex, y = ey;
    while(x != sx || y != sy){
        path.push_back(parent[x][y]);
        auto p = prev[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path;

    return 0;
}
