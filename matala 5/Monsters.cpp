#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s : grid) cin >> s;

    vector<vector<int>> monster(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> q;

    pair<int,int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i,j});
                monster[i][j] = 0;
            }
            if (grid[i][j] == 'A')
                start = {i,j};
        }
    }

    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,1,-1};

    while (!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;

            if (monster[nr][nc] > monster[r][c] + 1) {
                monster[nr][nc] = monster[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }

    queue<pair<int,int>> pq;
    pq.push(start);

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> parent(n, vector<char>(m));

    dist[start.first][start.second] = 0;

    if (start.first == 0 || start.second == 0 || start.first == n - 1 || start.second == m - 1){
        cout<<"YES\n0";
        return 0;
    }

    while (!pq.empty()){
        auto [r,c] = pq.front();
        pq.pop();

        for (int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;

            int nd = dist[r][c] + 1;

            if (nd >= monster[nr][nc]) continue;
            if (dist[nr][nc] <= nd) continue;

            dist[nr][nc] = nd;

            if (k == 0) parent[nr][nc]='D';
            if (k == 1) parent[nr][nc]='U';
            if (k == 2) parent[nr][nc]='R';
            if (k == 3) parent[nr][nc]='L';

            pq.push({nr,nc});

            if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1){
                string path;
                int cr=nr, cc=nc;

                while (make_pair(cr,cc)!=start) {
                    char p = parent[cr][cc];
                    path.push_back(p);

                    if (p == 'D') cr--;
                    if (p == 'U') cr++;
                    if (p == 'R') cc--;
                    if (p == 'L') cc++;
                }

                reverse(path.begin(), path.end());

                cout << "YES\n";
                cout << path.size() << "\n";
                cout << path;
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}