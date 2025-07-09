/*


all the code can be seen also at my github https://github.com/erri4/cpp for the file
hierarchy i use or anything you want to check.


*/


// ferris wheel
#include <iostream>
#include <vector>
#include <algorithm>

using str = std::string; // i dont use `using namespace std;`, because
using std::vector; // the youtube video that taught me c++
using std::sort; // said that std has a lot of members, so
using std::find; // for example, i do use `using namespace std;`, and i want
using std::cin; // to write a function called add_const, i can't!
using std::cout; // the name add_const and many others are taken!
                // that is why i am `using` only a few members of std.


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

/*
time complexity: O(n log n) because of sort
sorting: O(n log n)

loop: O(n)

total: O(n log n)

space complexity: O(n) because of sort

algorithm:
sort the list of weights

define three counters:

g = 0 (gondolas)

i = 0 (lightest person)

j = n - 1 (heaviest person)

while i <= j:

if weights[i] + weights[j] <= max_weight, put both in one gondola and i++, j--, g++

else, weights[j] goes alone and j--, g++

proof it works:
first we sort all weights

in each step, we try pairing the lightest (weights[i]) and heaviest (weights[j]) remaining people

we have two people w[i] (lightest) and w[j] (heaviest):

if weights[i] + weights[j] <= max_weight, it is optimal to pair them

otherwise, we must put weights[j] with someone heavier than weights[i], or alone, but:

no one heavier than weights[i] will allow a better pairing

so not pairing weights[i] and weights[j] would result in more rides, which we dont want

so, pairing them (if they fit) is optimal

*/

// removal game

#include <iostream>
#include <vector>
#include <algorithm>

using str = std::string;
using std::vector;
using std::sort;
using std::find; // see lines 17-23 for explanation why i don't do `using namespace std;`
using std::max;
using std::cin;
using std::cout;

// for some reason it doesn't work when i am using int and not long long
long long max_score(vector<long long> array){
    vector<vector<long long>> dp(array.size(), vector<long long>(array.size(), 0));
    vector<long long> prefix(array.size() + 1, 0);
    for (long long i = 0; i < array.size(); ++i) {
        prefix[i + 1] = prefix[i] + array[i];
    }


    for (long long len = 1; len <= array.size(); ++len) {
        for (long long i = 0; i + len - 1 < array.size(); ++i) {
            long long j = i + len - 1;
            long long total = prefix[j + 1] - prefix[i];
            if (i == j) {
                dp[i][j] = array[i];
            } else {
                dp[i][j] = max(
                    array[i] + (total - array[i] - dp[i + 1][j]),
                    array[j] + (total - array[j] - dp[i][j - 1])
                );
            }
        }
    }

    return dp[0][array.size() - 1];
}


int main(){
    long long length;
    vector<long long> array;
    cin >> length;
    for (long long i = 0; i < length; i++){
        long long item;
        cin >> item;
        array.push_back(item);
    }
    cout << max_score(array);
    return 0;
}

/*
time Complexity: O(n^2)
we find dp[i][j] for every 0 <= i <= j < n
there are n(n+1)/2 = O(n^2) arrays

space complexity: O(n^2)

proof it works:
the idea is to recursively find the best move at every step. this needs to test subarrays [i, j] of A.
*/
int A[]; //ignore me!    /*
int total; //ignore me!         seriously, ignore this.
int i; //ignore me!
int j; //ignore me!      */
vector<vector<int>> dp; //ignore me!
/*
define:

dp[i][j] = the max score the first player can get on subarray A[i..j]
total = sum(A[i] to A[j]).
if it is the first player's turn on [i, j], and they choose:

A[i]: other will be left with [i+1, j]

A[j]: other will be left with [i, j-1]

because the other plays optimally, the score will be dp[i+1][j] or dp[i][j-1].

so, if you take A[i], your added score is:
*/
int placeholder = A[i] + (total - A[i] - dp[i+1][j]);
//    =
int placeholder = total - dp[i+1][j];
/*
similar for A[j]: total - dp[i][j-1]

so this is:

dp[i][j] = max(total - dp[i+1][j], total - dp[i][j-1])

base case:

dp[i][i] = A[i]

*/

//projects

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::cout;
using std::cin;

struct Project {
    long long start, end, reward;
};

bool compareByEnd(const Project& a, const Project& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compareByEnd);

    vector<long long> ends;
    for (auto& p : projects) {
        ends.push_back(p.end);
    }

    vector<long long> dp(n);

    for (int i = 0; i < n; ++i) {
        int j = lower_bound(ends.begin(), ends.end(), projects[i].start) - ends.begin() - 1;

        long long bestBefore = (j >= 0 ? dp[j] : 0);
        dp[i] = max((i > 0 ? dp[i - 1] : 0), bestBefore + projects[i].reward);
    }

    cout << dp[n - 1] << "\n";

    return 0;
}


/*
time complexity:
sorting: O(n log n)
binary Search: O(log n)
loop over all projects: O(n)
total: O(n log n)

space complexity: O(n)

proof it works:

algorithm outline:
sort by end time.

define dp[i] = maximum profit from first i + 1 projects.

for each project i, you have two options:

skip: profit is dp[i-1]

take: add its profit to dp[j], when j is the last project that ends before project i (found with binary search).

take the max of the two options:

dp[i] = max(dp[i-1], (profit of project i) + dp[j])

proof:
define dp[i] be the optimal value for first i+1 projects.

dp[k] gives optimal value for all k < i.

then for project i, two cases:

project i is excluded: the best profit is dp[i - 1].

project i is included: to prevent overlap, find the last compatible project j where end[j] < start[i].

total profit becomes dp[j] + (profit of project i).

then:

dp[i] = max(dp[i-1], dp[j] + (profit of project i))

builds up the solution from base case (0 projects) to full case (n projects), always ensuring the maximum possible profit is stored.

with induction, we conclude dp[n-1] gives the maximum profit.
*/