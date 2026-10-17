template <typename T>
struct Node{
    T data;
    Node<T>* prev = nullptr;
};

template <typename _T>
class queue{ // -> push > head ... tail > pop/front
    protected:
    Node<_T>* head = nullptr;
    Node<_T>* tail = nullptr;
    public:
    queue() = default;

    void pop(){
        if (!empty()){
            this->tail = this->tail->prev;
        }
        if (this->tail == nullptr) this->head = nullptr;
    }

    _T front(){
        if (!empty()) return this->tail->data;
        return 0;
    }

    void push(_T data){
        if (empty()){
            this->head = new Node<_T>{data};
            this->tail = this->head;
            return;
        }
        if (this->head == this->tail){
            this->head = new Node<_T>{data};
            this->tail->prev = this->head;
            return;
        }
        Node<_T>* nd = new Node<_T>{data};
        this->head->prev = nd;
        this->head = nd;
    }

    bool empty() const{
        return head == nullptr;
    }

    queue(const queue& other) = delete;
    queue& operator=(const queue& other) = delete;

    ~queue(){
        while (!empty()){
            pop();
        }
    }
};
