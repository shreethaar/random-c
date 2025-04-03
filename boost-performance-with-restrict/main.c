// the restrict keywords tells the compiler:
// -- these pointers do not overlop, so optimize aggressively
// -- this allows better memory access optimizations and faster execution
//
// why this is better ?
// -- allows full compiler optimizations
// -- prevents unnecessary memory reloads
// -- faster and more efficient execution
//
// use restrict when you're sure pointers wont overlop for maximum performance

#include <stddef.h>
#include <stdio.h>

// without restrict (potential overlap)
void copy_no_restrict(int *dst, const int *src, size_t n) {
    for(size_t i = 0; i<n ;i++) {
        dst[i]=src[i];
    }

}

void copy_with_restrict(int *restrict dst, const int *restrict src, size_t n) {
    for(size_t i = 0; i<n; i++) {
        dst[i]=src[i];
    }
}

int main() {
    int src[] = {1,2,3,4,5};
    int dst[5];

    // example of possible memory overlap
    // slower due to assumed aliasing
    copy_no_restrict(src+1,src,4);


    // example with restrict, ensuring separate memory regions
    copy_with_restrict(dst,src,5);   // faster execution

    for(int i=0;i<5;i++) {
        printf("%d ",dst[i]);
    }
    return 0;
}
