#include <iostream>
#include <vector>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector, std::pair;

ll MaximumSubarraySum(vector<ll> nums){
    ll sum = nums[0];
    for (ll num : nums){
        if (sum + num > num){
            sum += num;
        }
        else{
            sum = num;
        }
    }
    return sum;
}


int main(){
    ll n;
    input(n);
    vector<ll> nums;
    ll num;
    for (ll i = 0; i < n; i++){
        input(num);
        nums.push_back(num);
    }
    print(MaximumSubarraySum(nums));
    return 0;
}
