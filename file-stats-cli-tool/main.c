// parse args, handle files and use signals for robust control

#include <signal.h>
#include <stddef.h>
#include <stdio.h>
volatile sig_handler(int _) {run=0;}

int main(int argc, char** argv) {
    signal(SIGINT,sig_handler);
    if(argc<2) {
        printf("Usage: %s <file>\n",argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1],"r");
    if(!f) {
        perror("fopen");
        return 1;
    }

    size_t lines = 0;
    char c;
    while(run && (c = fgetc(f)) != EOF) 
        if(c=='\n') lines ++;

    printf("Lines: %zu\n",lines);
    fclose(f);
    return 0;
}

