#include <iostream>


namespace defaultns{
	using str = std::string;

	void print(str data){
		std::cout << data << '\n';
	}

	void print(int data){
		std::cout << data << '\n';
	}

	void print(char data){
		std::cout << data << '\n';
	}

	str input(str prompt = ""){
		str input;
		std::getline(std::cin, input);
		return (str)input;
	}

	int intput(str prompt = ""){
		int input;
		std::cin >> input;
		return input;
	}
}


int main(){
	using namespace defaultns;
	str shimi;
	print("write shimi hakadosh");
	shimi = input();
	while (shimi != "shimi hakadosh"){
		print("traitor!");
		print("write shimi hakadosh");
		shimi = input();
	}
	int shimin;
	print("how many times you want shimi? ");
	shimin = intput();
    for (int i = 0; i < shimin; i++){
        print("shimi hakadosh");
    }

    system("pause");
    system("exit");
    
	return 0;	
}
