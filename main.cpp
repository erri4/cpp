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
		if (prompt != ""){
			print(prompt);
		}
		std::getline(std::cin, input);
		return (str)input;
	}

	int intput(str prompt = ""){
		int input;
		if (prompt != ""){
			print(prompt);
		}
		std::cin >> input;
		return input;
	}
}


int main(){
	using namespace defaultns;
	print("Running shimirit program.");
	str shimi;
	shimi = input("write shimi hakadosh: ");
	while (shimi != "shimi hakadosh"){
		print("traitor!");
		shimi = input("write shimi hakadosh: ");
	}
	int shimin;
	shimin = intput("how many times you want shimi? ");
    for (int i = 0; i < shimin; i++){
        print("shimi hakadosh");
    }

    system("pause");
    system("exit");
    
	return 0;	
}
