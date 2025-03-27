#include <stdio.h>
#include <string.h>

void demonstrate_rep_instruction() {
    // demonstrate of rep movsb (memory copy) 
    char source[] = "Hello, world!";
    char destination[20] = {0}; // initialize with zeros

    printf("rep movsb (Memory Copy):\n");
    printf("Source: %s\n",source);

    // In assembly, this is equivalent to:
    // mov esi, source 
    // mov edi, destination 
    // mov ecx, length of source 
    // rep movsb 
    memcpy(destination,source,strlen(source)+1);
    printf("Destination: %s\n\n",destination);

    // demonstration of rep stosb (memory set) 
    char buffer[10];
    printf("rep stosb (Memory Set):\n");
    // In assembly, this is equivalent to:
    // xor eax, eax // SET AL to 0
    // mov edi, buffer
    // mov ecx, sizeof(buffer) 
    // rep stosb 
    memset(buffer,0,sizeof(buffer));
    printf("Buffer initialized to zeros: ");
    for(int i=0;i<sizeof(buffer);i++) {
        printf("%02x ",buffer[i]);
    }
    printf("\n\n");

    // demonstration of repe cmpsb (buffer comparison) 
    char buffer1[] = "Hello, world!";
    char buffer2[] = "Hello, world!";
    char buffer3[] = "Hello, universe!";
    printf("repe cmpsb (Buffer comparison):\n");
    printf("comparing buffer1 and buffer2: %s\n",memcmp(buffer1,buffer2,strlen(buffer1))==0 ? "Equal" : "Not Equal");
    printf("comparing buffer1 and buffer3: %s\n\n",memcmp(buffer1,buffer3,strlen(buffer1))==0 ? "Equal" : "Not Equal");

    // demonstration of repne scasb (byte search) 
    char search_buffer[]="Hello,world!";
    char target='o';
    // In assembly, this would be equivalent to: 
    // mov al, target
    // mov edi, search_buffer 
    // mov ecx, length of buffer 
    // repne scasb 

    char* found = memchr(search_buffer,target,strlen(search_buffer));
    if(found) {
        printf("Found '%c' at index: %ld\n",target,found-search_buffer);
    }

    else {
        printf("'%c' not found in the buffer\n",target);
    }
}



int main() {
    demonstrate_rep_instruction();
    return 0;
}

