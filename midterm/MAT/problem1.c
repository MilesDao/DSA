#include<stdio.h>

typedef struct {
    int fn_1;
    int fn_2;
} FibPair;

FibPair init(){
    FibPair fb;
    fb.fn_1 = 1;
    fb.fn_2 = 0;
    return fb;
}

FibPair calculate(int n){
    if( n == 1) return init();
    
    FibPair prev = calculate(n - 1);
    FibPair i;
    i.fn_1 = prev.fn_1 + prev.fn_2;
    i.fn_2 = prev.fn_1;
    return i;
}
void display(int pos){
    FibPair res = calculate(pos);
    printf("F(%d) = %d\n", pos, res.fn_1);
}
int main(){
    int n = 8;
    display(n);

    return 0;
}
