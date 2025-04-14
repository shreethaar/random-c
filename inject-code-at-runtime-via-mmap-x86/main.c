#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main() {
    // mov eax, 42; ret
    char code[] = {0xb8, 0x2a, 0x00, 0x00, 0x00, 0xc3};
    void* mem = mmap(0,4096,PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);
    memcpy(mem,code,sizeof(code));
    int(*fn)() = mem;
    printf("%d\n",fn()); // prints 42
}
