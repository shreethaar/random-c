#include <stddef.h>
#include <stdio.h>
#include <string.h>

// function: rep_movsb
// description: copy count bytes from src to dest 
// parameter 'forward' controls direction: if non-zero, copu forward; else, copy backwards.
//
void rep_movsb(unsigned char *dest, const unsigned char *src, size_t count, int forward) {
    if(forward) {
        for(size_t i=0;i<count;i++) {
            dest[i]=src[i];
        }
    }
    else {
        // reverse copy: start from the end 
        for(size_t i=count;i>0;i--) {
            dest[i-1]=src[i-1];
        }
    }
}

// function: rep_cmpsb
// description: compare two buffers byte by byte 
// returns 0 if the buffers match completely, otherwise the difference between the mismatched bytes 

int rep_cmpsb(const unsigned char *buf1, const unsigned char *buf2, size_t count, int forward) {
    if(forward) {
        for(size_t i=0;i<count;i++) {
            if(buf1[i]!=buf2[i])
                return (int)buf1[i]-(int)buf2[i];
        }
    }
    else {
        for(size_t i=count;i>0;i--) {
            if(buf1[i-1]!=buf2[i-1]) 
                return (int)buf1[i-1]-(int)buf2[i-1];
        }
    }
    return 0;
}

// function: rep_stosb 
// description: fill count bytes at dest with the given value 
void rep_stosb(unsigned char *dest, unsigned char value, size_t count, int forward) {
    if(forward) {
        for(size_t i=0;i<count;i++) {
            dest[i]=value;
        }
    } else {
        for(size_t i=count;i>0;i--) {
            dest[i-1]=value;
        }
    }
}

// function: rep_scasb
// description: search for the first occurence of value in a buffer 
// returns the index of the found byte or -1 if not found 
int rep_scasb(const unsigned char *buf, unsigned char value, size_t count, int forward) {
    if(forward) {
        for(size_t i=0;i<count;i++) {
            if(buf[i]==value)
                return (int)i;
        }

    }
    else {
        for(size_t i=count;i>0;i--) {
            if(buf[i-1]==value) 
                return (int)(i-1);
        }
    }
    return -1;
}

int main(void) {
    // Demonstrate rep_movsb (copying a string)
    unsigned char source[] = "Hello, World!";
    unsigned char dest[50] = {0};

    printf("Before rep_movsb, dest: \"%s\"\n", dest);
    // Copy forward (like DF = 0)
    rep_movsb(dest, source, strlen((char *)source) + 1, 1);
    printf("After rep_movsb (forward), dest: \"%s\"\n", dest);

    // Reverse copy (simulate DF = 1; in this case the result is the same)
    unsigned char rev[50] = {0};
    rep_movsb(rev, source, strlen((char *)source) + 1, 0);
    printf("After rep_movsb (reverse), rev: \"%s\"\n\n", rev);

    // Demonstrate rep_cmpsb (comparing two buffers)
    unsigned char buf1[] = "TestBuffer";
    unsigned char buf2[] = "TestBuffer";
    int cmpResult = rep_cmpsb(buf1, buf2, strlen((char *)buf1), 1);
    printf("rep_cmpsb (forward) result: %d (0 indicates match)\n", cmpResult);

    // Modify buf2 and compare again
    buf2[4] = 'X';
    cmpResult = rep_cmpsb(buf1, buf2, strlen((char *)buf1), 1);
    printf("rep_cmpsb (forward) result after modification: %d (non-zero indicates difference)\n\n", cmpResult);

    // Demonstrate rep_stosb (filling a buffer)
    unsigned char buffer[20];
    rep_stosb(buffer, 'A', sizeof(buffer) - 1, 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null-termination for printing
    printf("rep_stosb (forward) result (fill with 'A'): \"%s\"\n", buffer);

    // Reverse fill (simulate reverse operation)
    unsigned char bufferRev[20];
    rep_stosb(bufferRev, 'B', sizeof(bufferRev) - 1, 0);
    bufferRev[sizeof(bufferRev) - 1] = '\0';
    printf("rep_stosb (reverse) result (fill with 'B'): \"%s\"\n\n", bufferRev);

    // Demonstrate rep_scasb (searching for a byte)
    unsigned char searchBuf[] = "Find the character 'c' in this string.";
    int pos = rep_scasb(searchBuf, 'c', strlen((char *)searchBuf), 1);
    if (pos >= 0)
        printf("rep_scasb (forward) found 'c' at position: %d\n", pos);
    else
        printf("rep_scasb (forward) did not find 'c'\n");

    // Reverse search for the same byte
    pos = rep_scasb(searchBuf, 'c', strlen((char *)searchBuf), 0);
    if (pos >= 0)
        printf("rep_scasb (reverse) found 'c' at position: %d\n", pos);
    else
        printf("rep_scasb (reverse) did not find 'c'\n");

    return 0;
}


