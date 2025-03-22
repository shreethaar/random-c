// String Processing
// A program that reads a line of text from standard input and performs the following operations:
// 1. Count the number of alphabetic, numeric and special characters
// 2. Convert lowercase letters to uppercase and vice versa
// 3. Print both the original and modified strings along with the characters counts 
//

#include <stdio.h>

#define MAX_LEN 20

void transform(char *buf) {
    for(int i=0;i<MAX_LEN-1;++i) {
        if(buf[i]>='a' && buf[i] <= 'z') {
            buf[i]=buf[i]-'a'+'A';
        }
        else {
            buf[i]=buf[i]-'A'+'a';
        }
    }
    printf("Modified String: %s\n", buf);
}


int main() {
    char buf[MAX_LEN] = "";
    printf("String Processing Program\n");
    printf("Enter a string: ");
    scanf("%s",buf);
    printf("Original String: %s\n",buf);
    transform(buf);


    

    return 0;
}
