template <typename T>
struct Node{
    T data;
    Node<T>* next = nullptr;
};

template <typename _T>
class stack{
    protected:
    Node<_T>* head = nullptr;
    public:
    stack() = default;

    void pop(){
        if (!empty()){
            Node<_T>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }

    _T top(){
        if (!empty()) return this->head->data;
        return 0;
    }

    void push(_T data){
        Node<_T>* nd = new Node<_T>{data, this->head};
        this->head = nd;
    }

    bool empty() const{
        return head == nullptr;
    }

    stack(const stack& other) = delete;
    stack& operator=(const stack& other) = delete;

    ~stack(){
        while (!empty()){
            pop();
        }
    }
};
