#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct {
    char* buf;
    size_t len,cap;
} dstr_t;

dstr_t* dstr_new(const char* init) {
    dstr_t* s = malloc(sizeof(dstr_t));
    s->len=strlen(init);
    s->cap=s->len+8;
    s->buf=malloc(s->cap);
    strcpy(s->buf,init);
    return s;
}

void dstr_append(dstr_t* s, const char* text) {
    size_t textlen = strlen(text);
    if(s->len+textlen+1>s->cap) {
        s->cap=s->len+textlen+16;
        s->buf=realloc(s->buf,s->cap);

    }
    strcpy(s->buf+s->len,text);
    s->len+=textlen;
}


int main() {
   dstr_t* s = dstr_new("go ");
   dstr_append(s,"touch ");
   dstr_append(s,"some grass");
   printf("%s\n",s->buf);
   free(s->buf);
   free(s);
    return 0;
}

