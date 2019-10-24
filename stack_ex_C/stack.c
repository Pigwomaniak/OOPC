//
// Created by maciek on 24/10/2019.
//

#include "stack.h"
#include <stdio.h>

void init(Stack *s){
    s->data = NULL;
    s->top = 0;
    s->allocatedMemory = 0;
}
void destroy(Stack* s){
    free(s->data);
}
void push(Stack* s, int element){
    if(s->top >= s->allocatedMemory){
        if(s->allocatedMemory == 0){
            s->allocatedMemory = 1;
        }else{
            s->allocatedMemory *= 2;
        }
        if(!(s->data = realloc(s->data, (size_t)((s->allocatedMemory) * sizeof(int))))){
            printf("realloc fail");
            exit(0);
        }
    }
    s->data[s->top] = element;
    s->top++;
}
int pop(Stack* s){
    if(s->top){
        return s->data[--(s->top)];
    }
    printf("Empty stack    ");
    return 0;
}
bool isEmpty(Stack* s){
    if(s->top){
        return 0;
    }
    return 1;
}
void copyStack(Stack *outS, Stack *sourceS){
    int current = 0;
    while(outS->top < sourceS->top){
        push(outS, sourceS->data[current++]);
    }
}

void rewriteStack(Stack *outS, Stack *sourceS){
    if(outS == sourceS){
        return;
    }
    if(outS->data){
        free(outS->data);
    }
    if(!(outS->data = realloc(outS->data, (size_t)sourceS->allocatedMemory))){
        exit(0);
    }
    outS->allocatedMemory = sourceS->allocatedMemory;
    outS->top = 0;
    int current = 0;
    while(outS->top < sourceS->top){
        push(outS, sourceS->data[current++]);
    }
}
