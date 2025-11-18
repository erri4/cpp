#include <vector>
using std::vector;


class heap {
    private:
        vector<int> data;
    public:
        heap(){}

        void insert(int item){}
        
        int& operator[](size_t index){
            return data[index];
        }

        const int& operator[](size_t index) const{
            return data[index];
        }
};

int main(){
    return 0;
}