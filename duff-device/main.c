#include <stdio.h>


void copy(char* to, char* from, int count) {
    int n = (count+7)/8;
    switch(count%8) {
        case 0: do {*to++ = *from++;
        case 7: *to++ = *from++;
        case 6: *to++ = *from++;
        case 5: *to++ = *from++;
        case 4: *to++ = *from++;    
        case 3: *to++ = *from++;
        case 2: *to++ = *from++; 
        case 1: *to++ = *from++;
                } while(--n > 0);
    }

}

int main() {
    char* src = "touch some grass instead of optimizing this loop";
    char dst[100] = {0};
    int hours_spent_optimizing=0;

    copy(dst,src,sizeof(src));
    printf("%s\n",dst);
    return hours_spent_optimizing > 0 ? 1: 0;
}


