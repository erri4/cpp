#include <iostream>
using namespace std;
 
 
void TowerOfHanoi(int n, int source, int destination, int auxiliary, int &moveCount) {
    if (n == 1) {
        cout << source << " " << destination << '\n';
        moveCount++;
        return;
    }
    
    TowerOfHanoi(n - 1, source, auxiliary, destination, moveCount);
    
    cout << source << " " << destination << '\n';
    moveCount++;
    
    TowerOfHanoi(n - 1, auxiliary, destination, source, moveCount);
}
 
int main() {
    int n;
    cin >> n;
    
    int moveCount;
    
    moveCount = (1 << n) - 1;
    
    cout << moveCount << '\n';
    
    TowerOfHanoi(n, 1, 3, 2, moveCount);
    
    return 0;
}