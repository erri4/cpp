#include <iostream>
#include <cmath>

long long factorial(long long x) {
    long long result = 1;
    for (long long i = 2; i <= x; ++i)
        result *= i;
    return result;
}

long long cosFloor(long long j) {
    double val = std::cos(M_PI * (factorial(j-1) + 1) / j);
    return std::floor(val * val);
}

long long innerSum(long long i) {
    long long sum = 0;
    for (long long j = 1; j <= i; ++j) {
        sum += cosFloor(j);
    }
    return sum;
}

long long computeFormula(long long n) {
    long long total = 1;
    long long outerLimit = 1 << n;
    for (long long k = 1; k <= outerLimit; ++k) {
        long long sum = innerSum(k);
        total += std::floor(std::pow(static_cast<double>(k) / sum, 1.0 / n));
    }
    return total;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i){
        std::cout << i << ' ' << computeFormula(i) << '\n';
    }
    return 0;
}
