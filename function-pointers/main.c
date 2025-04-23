#include <stdio.h>

#define NUM_FUNCS 3

void 
f1 (int a, int b) {
    printf("f1: %d %d\n",a,b);
}


void 
f2 (int a, int b) {
    printf("f2: %d %d\n",a,b);
}

void 
f3 (int a, int b) {
    printf("f3: %d %d\n",a,b);
}

int 
main (int argc, char** argv) {

    void(*f[NUM_FUNCS]) (int,int)= {f1,f2,f3};
    
    for(int i=0;i<NUM_FUNCS;i++) {
        f[i](i,i+1);
    }
    
    return 0;

}

