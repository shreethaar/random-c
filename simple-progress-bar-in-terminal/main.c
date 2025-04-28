#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Loading: [");
    for(int i=0;i<20;i++) {
        fflush(stdout);
        usleep(10000);
        printf("#");
    }
    printf("] Done !\n");
    return 0;
}
