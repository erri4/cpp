#include <iostream>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;

template<typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
};


template<typename T>
bool question3A(Node<T>* head){
    Node<T> curr = *((*head).next);
    while (true){
        if (curr.next == head){
            return true;
        }
        if (curr.next == nullptr){
            return false;
        }
        curr = *(curr.next);
    }
}

template<typename T>
Node<T>* itemplusk(Node<T>* item, int k){
    while (item != nullptr && k-- > 0) {
        item = item->next;
    }
    return item;
}

template<typename T>
T question3B(Node<T>* head, int k){
    if (question3A(head)){
        print("there's no end");
        system("exit");
    }
    auto curr = *head;
    while (!(itemplusk(&curr, k)->next == nullptr)){
        curr = *(curr.next);
    }
    return curr.data;
}

int main(){
    return 0;
}