//
// Created by maciek on 24/10/2019.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int top;
    int *data;
    int allocatedMemory;
} Stack;

void init(Stack *s);
void destroy(Stack *s);
void push(Stack *s, int element);
int pop(Stack *s);
bool isEmpty(Stack *s);
void copyStack(Stack *outS, Stack *sourceS);
void rewriteStack(Stack *outS, Stack *sourceS);

#endif //UNTITLED_STACK_H
