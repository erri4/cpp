#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Function to check if it's safe to place a queen
bool isSafe(const vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int row, int c) {
    int n = board.size();
    return !col[c] && !diag1[row + c] && !diag2[row - c + n - 1] && board[row][c] == '.';
}
 
// Backtracking function to count the solutions
void solve(const vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int row, int& count) {
    int n = board.size();
    if (row == n) {
        count++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (isSafe(board, col, diag1, diag2, row, c)) {
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;
            solve(board, col, diag1, diag2, row + 1, count);
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }
}
 
int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    
    vector<bool> col(8, false); // Keeps track of columns
    vector<bool> diag1(15, false); // Keeps track of main diagonals
    vector<bool> diag2(15, false); // Keeps track of anti-diagonals
    
    int count = 0;
    solve(board, col, diag1, diag2, 0, count);
    
    cout << count << endl;
    return 0;
}