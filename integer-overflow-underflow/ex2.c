#include <stdio.h>
#include <stdint.h>

uint64_t asm_subtraction() {
    uint64_t result;
    __asm__(
                "movq $0x97FFEBAB119F0B40, %%rax\n"
                "movq $0x216E4178E0D80721, %%rbx\n"
                "subq %%rbx, %%rax\n"
                "movq %%rax, %[res]\n"
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
