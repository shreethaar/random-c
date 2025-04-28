#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    char password[12];
    srand(time(NULL));
    for(int i=0;i<11;i++) {
        password[i]=charset[rand()%(sizeof(charset)-1)];
        password[11]='\0';
    }
    printf("Password: %s\n",password);
    return 0;
}
