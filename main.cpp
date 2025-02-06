#include <iostream>

using str = std::string;

int main(){
	str shimi;
	std::cout << "write shimi hakadosh" << '\n';
	std::getline(std::cin, shimi);
	while (shimi != "shimi hakadosh"){
		std::cout << "traitor!" << '\n';
		std::cout << "write shimi hakadosh" << '\n';
		std::getline(std::cin, shimi);
	}
	int shimin;
	std::cout << "how many times you want shimi? ";
	std::cin >> shimin;
    for (int i = 0; i < shimin; i++){
        std::cout << "shimi hakadosh" << '\n';
    }

    system("pause");
    system("exit");
    
	return 0;	
}
