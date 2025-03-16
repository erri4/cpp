#include <iostream>
#include <vector>
#include <algorithm>


namespace defaultns{
    using str = std::string;

    void printf(int data, char end = '\n'){std::cout << data << end;}
    void printf(str data, char end = '\n'){std::cout << data << end;}
}

using namespace defaultns;

int func(str n){
    std::vector<long long> results;

    int temp = 0;
	for (int i = 0; i < n.size() - 1; i++){
        if (n[i] == n[i + 1]){
            temp++;
        }
        else {
            results.push_back(temp);
            temp = 0;
        }
    }

    results.push_back(temp);
	return *std::max_element(results.begin(), results.end()) + 1;
}


int main(){
	str dna;
	std::cin >> dna;
	printf(func(dna));
	return 0;
}