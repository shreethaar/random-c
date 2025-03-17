#include <stdio.h>
#include <stdlib.h>

// Bug code: Buffer Flushing Issue
/*
 * int myfunction(int counter) {
    int result=5;
    printf("myfunction %p %p %p\n",&result,&counter,__builtin_frame_address(0));
    return 0;
}


int main() {
    int i;
    printf("main %p %p\n",&i,__builtin_frame_address(0));
    myfunction(4);
    return 0;
}
*/

int myfunction(int counter) {
    int result=5;
    printf("BEFORE myfunction print\n");
    printf("myfunction %p %p %p\n",&result,&counter,__builtin_frame_address(0));
    printf("AFTER myfunction print\n");
    fflush(stdout);  // Force buffer flush
    return 0;
}

int main() {
    int i;
    printf("main %p %p\n",&i,__builtin_frame_address(0));
    fflush(stdout);  // Force buffer flush
    printf("About to call myfunction\n");
    myfunction(4);
    printf("Returned from myfunction\n");
    fflush(stdout);  // Force buffer flush
    return 0;
}

/* 
 * This code is designed to show memory addresses of variables and the frame pointer in different functions on the stack. It will print the addresses of local variables and the frame address (stack pointer) for both main and myfunction
 *
 * The main elements:
 * 1. In main(), it print:
 * - the address of local variables i 
 * - the current frame address using __builtin_frame_address(0)
 * 
 * 2. In myfunction(), it print:
 * - the address of local variable result
 * - the address of parameter counter
 * - the current frame address 
 *
 * When executed, this program will show how these addresses relate to each other, demonstrating the stack's structure - specifically how local variables and parameters are laid out on the stack, how the frame pointer changes between function calls. 
 *
 */
