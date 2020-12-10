#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define RANGE 10000
struct dev_op {
    int cmd;
    int is_ok;
    char info[8];
};
struct dev {
    int sa;
    int sb;
    long lb;
    char c[32];
    struct dev_op op;
};
struct dev sharedArr;

void __attribute__ ((noinline)) foo(struct dev_op *op, int n) {
        op->is_ok = n*(n-1);
        // memset(op->info,n-1,8);
}
void __attribute__ ((noinline)) foox(struct dev_op *op, int n) {
        // op->is_ok = n*(n-1);
        memset(op->info,n-1,8);
}
void do_op(struct dev *data) {
    struct dev_op *op = &(data->op);
    switch(op->cmd) {
        case 1:
            foo(op, 1);
            break;
        case 2:
            foox(op, 2);
            break;
        case 3:
            foo(op, 3);
            break;
        case 4:
            foox(op, 4);
            break;
        case 5:
            foox(op, 5);
            break;
        case 6:
            foo(op, 6);
            break;
        case 7:
            foox(op, 7);
            break;
        case 8:
            foo(op, 8);
            break;
        default:
            op->is_ok = -1;
            break;
    }
}

int main(){
    do_op(&sharedArr);
}
