//
// Created by maciek on 24/10/2019.
//
#include "stack.h"
#include <stdio.h>
#include <assert.h>

#define NUM_OF_ELEMENTS 5

int main() {
    printf("hello\n");
    Stack s, s2, s3;
    init(&s);
    init(&s2);
    init((&s3));

    // Test for copyStack()

    for (int j = 0; j < NUM_OF_ELEMENTS; ++j) {
        push(&s, j);
    }
    copyStack(&s2, &s);
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        assert(pop(&s) == pop(&s2));
    }
    assert(isEmpty(&s) && isEmpty(&s2));
    printf("copyStack OK\n");

    // Test for rewriteStack()

	for (int j = 0; j < NUM_OF_ELEMENTS; ++j) {
        push(&s, j);
        push(&s2, j + 2);
    }
    push(&s2, 1);
	
    rewriteStack(&s2, &s);
	
    rewriteStack(&s3, &s);
	
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        int stack1 = pop(&s);
        int stack2 = pop(&s2);
        int stack3 = pop(&s3);
        //printf(" liczba %d ; %d ; %d", stack1, stack2, stack3);
        assert((stack1 == stack2) && (stack1 == stack3));
    }
    assert(isEmpty(&s) && isEmpty(&s2) && isEmpty(&s3));
    printf("rewriteStack OK\n");
    destroy(&s);
    destroy(&s2);
    destroy(&s3);
    printf("TEST COMPLETE\n");
    return 0;
}

