#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; int m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    string tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        grid[i] = vector<char>(tmp.begin(), tmp.end());
        for (int j = 0; j < m; j++) grid[i][j] -= 'A';
    }
    char curr;
    char prev;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            prev = grid[i][j];
            grid[i][j]++;
            grid[i][j] %= 4;
            if (i == 0 && j == 0){}
            else if (i == 0 && j > 0){
                if (grid[i][j - 1] == grid[i][j]){
                    while (grid[i][j - 1] == grid[i][j]){
                        grid[i][j]++;
                        grid[i][j] %= 4;
                        if (grid[i][j] == prev){
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
            else if (j == 0 && i > 0){
                if (grid[i - 1][j] == grid[i][j]){
                    while (grid[i - 1][j] == grid[i][j]){
                        grid[i][j]++;
                        grid[i][j] %= 4;
                        if (grid[i][j] == prev){
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
            else if (grid[i - 1][j] == grid[i][j] || grid[i][j - 1] == grid[i][j]){
                curr = grid[i][j];
                while (grid[i - 1][j] == grid[i][j] || grid[i][j - 1] == grid[i][j]){
                    grid[i][j]++;
                    grid[i][j] %= 4;
                    if (grid[i][j] == curr){
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                    if (grid[i][j] == prev){
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }
    for (auto row : grid){
        for (char letter : row){
            letter += 'A';
            cout << letter;
        }
        cout << '\n';
    }
    return 0;
}