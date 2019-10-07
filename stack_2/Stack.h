//
// Created by maciek on 07/10/19.
//

#ifndef STACK_2_STACK_H
#define STACK_2_STACK_H


#include <stdbool.h>

class Stack {
public:
    Stack();
    ~Stack();
    void push(int element);
    int pop();
    bool isEmpty();

private:
    int top;
    int* data;
    int allocatedMemory;
};


#endif //STACK_2_STACK_H
