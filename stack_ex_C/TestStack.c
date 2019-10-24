//
// Created by maciek on 24/10/2019.
//
#include "stack.h"
#include <stdio.h>

int main() {
    printf("hello\n");
    Stack s, s2;
    init(&s);
    init(&s2);
    printf("Is empty stack: %d \n",(int)isEmpty(&s));
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    copyStack(&s2, &s);
    printf("Is empty stack: %d \n",(int)isEmpty(&s));
    printf("%d \n",pop(&s));
    printf("%d \n",pop(&s));
    printf("%d \n",pop(&s));
    printf("%d \n",pop(&s));

    printf("%d \n",pop(&s2));
    printf("%d \n",pop(&s2));
    printf("%d \n",pop(&s2));
    destroy(&s);
    destroy(&s2);
    return 0;
}

