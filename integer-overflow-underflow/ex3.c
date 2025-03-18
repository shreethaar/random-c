#include <stdio.h>
#include <stdint.h>

uint64_t asm_subtraction() {
    uint64_t result;
    __asm__(
        "movq $0x55E2B01C52D44450, %%rax\n"  // Load minuend into RAX
        "movq $0x8788F7F5BEC5EEA5, %%rbx\n" // Load subtrahend into RBX
        "subq %%rax, %%rbx\n"               // Subtract RAX from RBX
        "movq %%rbx, %[res]\n"              // Store result in 'result'
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
