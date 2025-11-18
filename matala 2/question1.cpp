#include <iostream>
#include <stack>
#include <queue>
#define print(data) (std::cout << data << '\n')

using std::stack;
using std::queue;

template<typename T>
class _2Stack {
    private:
        T* arr;
        int size;
        int index1;
        int index2;

    public:
        _2Stack(int n) {
            size = n;
            arr = new T[2*n];
            index1 = -1;
            index2 = n;
        }

        int size1(){
            return size/2;
        }

        int size2(){
            return size/2;
        }

        void push1(T x) {
            if (index1 + 1 == index2) {
                print("Stack Overflow"); //:)
                return;
            }
            arr[++index1] = x;
        }

        void push2(T x) {
            if (index1 + 1 == index2) {
                print("Stack Overflow");
                return;
            }
            arr[--index2] = x;
        }

        bool empty1(){
            return this->size1() == 0;
        }

        bool empty2(){
            return this->size2() == 0;
        }

        void pop1() {
            if (index1 == -1) {
                print("Stack Underflow");
            }
            index1--;
        }

        void pop2() {
            if (index2 == size) {
                print("Stack Underflow");
            }
            index2++;
        }

        T top1(){
            return arr[index1];
        }

        T top2(){
            return arr[index2];
        }

        ~_2Stack() {
            delete[] arr;
        }
};

template<typename T>
class Queue {
    private:
        stack<T> popfront;
        stack<T> pushback;

        void swap(){
            if (pushback.size()){
                while (!pushback.empty()){
                    popfront.push(pushback.top());
                    pushback.pop();
                }
            }
            else {
                while (!popfront.empty()){
                    pushback.push(popfront.top());
                    popfront.pop();
                }
            }
        }

    public:
        Queue(){}

        int size(){
            return pushback.size() + popfront.size();
        }

        T front(){
            if (pushback.size()){
                this->swap();
            }
            return popfront.top();
        }

        T back(){
            if (popfront.size()){
                this->swap();
            }
            return pushback.top();
        }
        
        void pop(){
            if (pushback.size()){
                this->swap();
            }
            popfront.pop();
        }

        void push(T item){
            if (popfront.size()){
                this->swap();
            }
            pushback.push(item);
        }

        bool empty(){
            return this->size() == 0;
        }
};

template<typename T>
class Stack {
    private:
        queue<T> tmp;
    public:
        queue<T> pushtop;
        Stack(){}

        void pop(){
            while (!pushtop.empty()){
                tmp.push(pushtop.front());
                pushtop.pop();
            }
            while (tmp.size() > 1){
                pushtop.push(tmp.front());
                tmp.pop();
            }
            tmp.pop();
        }

        T top(){
            return pushtop.back();
        }

        void push(T item){
            pushtop.push(item);
        }

        int size(){
            return pushtop.size();
        }

        bool empty(){
            return this->size() == 0;
        }
};

int main(){
   
    return 0;
}