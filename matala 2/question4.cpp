#include <iostream>
#include <cstdlib>
#include <ctime>


struct car{
    bool lamp;
    car* next;
};

int len(car* head){
    (*head).lamp = true;
    while (true){
        auto curr = (*head).next;
        int k = 1;
        while (!(*curr).lamp){
            curr = (*curr).next;
            k++;
        }
        (*curr).lamp = false;
        curr = head;// simulate going backwards k places
        if (!(*head).lamp){
            return k;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int N = 10;
    car* head = nullptr;
    car* prev = nullptr;

    for (int i = 0; i < N; ++i) {
        car* node = new car;
        node->lamp = std::rand() % 2;
        node->next = nullptr;

        if (!head) head = node;
        else prev->next = node;

        prev = node;
    }

    prev->next = head;
    std::cout << len(head);

    return 0;
}
