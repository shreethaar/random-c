#include <stdio.h>
#include <stdint.h>

uint64_t asm_subtraction() {
    uint64_t result;
    __asm__(
        "movq $0x82B24780E7F6A2C3, %%rax\n"  // Load minuend into RAX
        "movq $0x99241A314AF839AE, %%rbx\n" // Load subtrahend into RBX
        "subq %%rbx, %%rax\n"               // Subtract RBX from RAX
        "movq %%rax, %[res]\n"              // Store result in 'result'
        : [res] "=r" (result)               // Output operand
        :                                   // No input operands
        : "rax", "rbx"                      // Clobbered registers
    );
    return result;
}

int main() {
    uint64_t value = asm_subtraction();
    printf("Result: 0x%lx\n", value);
    return 0;
}
