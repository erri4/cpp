#include <iostream>
#include <vector>
#include <algorithm>
 
using str = std::string;
using std::vector;
using std::sort;
using std::find;
using std::cin;
using std::cout;
 
 
int match(int max_weight, vector<int> weights){
    sort(weights.begin(), weights.end());
    int gondolas = 0;
    int i = 0;
    int j = weights.size() - 1;
    while (i <= j){
        if (weights[i] + weights[j] <= max_weight){
            i++;
        }
        j--;
        gondolas++;
    }
    return gondolas;
}
 
 
int main(){
    int kids;
    int max_weight;
    vector<int> weights;
    cin >> kids;
    cin >> max_weight;
    for (int i = 0; i < kids; i++){
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }
    cout << match(max_weight, weights);
    return 0;
}