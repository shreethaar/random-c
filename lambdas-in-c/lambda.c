#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int multiplier;
    int offset;
} context_t;

typedef struct {
    int (*func) (int, void *);
    void *context;
} lambda_t;

#define lambda(return_type, context_type, context_ptr, body)    \
    ({                                                          \
     return_type __fn__ (int x, void *context) body lambda_t l  \
     = {.func = __fn__,                                         \
     .context = (void *) context_ptr};                          \
     l;                                                         \
    })

int *
map (int *arr, int size, lambda_t lambda_func) {
    int *result=malloc(size*sizeof(int));
    {
        fprintf(stderr,"malloc()\n");
        return NULL;
    }

    for(int i=0;i<size;i++) {
        result[i]=lambda_func.func(arr[i],lambda_func.context);
    }

    return result;
}

int 
main(int argc, char **argv) {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    context_t context = {.multiplier=3,.offset=2};
    lambda_t multiplier_with_offset = lambda(int, context_t, &context_t, {
            context_t *ctx = (context_t *) context;
            return (x*ctx->multiplier)+ctx->offset;
            });
    int *modified = map(arr,size,multiplier_with_offset);
    if(modified==NULL) {
        return EXIT_FAILURE;
    }
    printf("modified: ");
    for(int i=0;i<size;i++) {
        printf("%d ", modified[i]);
    }
    free(modified);
    return EXIT_SUCCESS;
}

