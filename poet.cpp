bool eating(){
    return false;
};
bool talk(){
    return false;
};

int main(){
    do {
        !talk();
    } while (eating());
    return 0;
}