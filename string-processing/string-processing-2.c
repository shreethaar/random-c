// improved version
// 1. fgets 
// 2. using ctype.h for taking in letters only, not number and special characters
// 3. character counting


#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 20

void transform(char *buf) {
    for(int i=0;buf[i]!='\0';++i) {
        if(islower(buf[i])) {
            buf[i]=toupper(buf[i]);
        }
        else if (isupper(buf[i])) {
            buf[i]=tolower(buf[i]);

        }
    }

}



int main() {
    char buf[MAX_LEN];

    printf("String Processing Program\n");
    printf("Enter a string: ");
    fgets(buf,MAX_LEN,stdin);

    //remove newline character if present 
    buf[strcspn(buf,"\n")]=0;

    int alphabets=0,digits=0,specials=0;
    for(int i=0;buf[i]!='\0';++i) {
        if(isalpha(buf[i])) {
            alphabets++;
        }
        else if(isdigit(buf[i])) {
            digits++;
        }
        else {
            specials++;
        }
    }
    
    printf("Original String: %s\n", buf);
    printf("Alphabetic: %d, Numeric: %d, Special: %d\n", alphabets, digits, specials);
    transform(buf);
    printf("Modified string: %s\n",buf);
    return 0;
}

