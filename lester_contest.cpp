int pow(int b, int exponent){
    int r = 1;
    for (int i = 0; i < exponent; i++){
        r *= b;
    }
    return r;
}


int ntower(int a, int b, int n){
    /*
    a^^^^^^...^^^b
     ------------
           n
    */
    if (n == 1) {
        return pow(a, b);
    }
    if (b == 1) {
        return a;
    }
    return ntower(a, ntower(a, b - 1, n), n - 1);
}

int graham(int n) {
    if (n == 1) {
        return ntower(3, 3, 4);
    }
    int prev = graham(n - 1);
    return ntower(3, 3, prev);
}

int main(){
    return graham(64);
}
