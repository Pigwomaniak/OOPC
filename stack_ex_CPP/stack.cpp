//
// Created by maciek on 24/10/2019.
//

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>

Stack::Stack(){
    top = 0;
    data = nullptr;
    allocatedMemory = 0;
}
Stack::Stack(Stack *sourceS) {
    this->top = 0;
    this->allocatedMemory = sourceS->allocatedMemory;
    this->data = (int*)realloc(nullptr, (size_t)(allocatedMemory * sizeof(int)));
    assert(this->data);
    int current = 0;
    while (this->top < sourceS->top){
        this->push(sourceS->data[current++]);
    }
}

void Stack::push(int element) {
    if(allocatedMemory <= top){
        if(!(data = (int *)realloc(data, (allocatedMemory + 5) * sizeof(int)))) {
            std::cout << "realloc fail";
            exit(0);
        }
        allocatedMemory += 5;
    }
    data[top++] = element;
}

int Stack::pop() {
    if(!top){
        std::cout << "Empty stack \n";
        return 0;
    }
    return data[--top];
}

bool Stack::isEmpty() {
    return top == 0;
}

Stack::~Stack() {
    free(data);
}
Stack& Stack::operator=(const Stack &srcS) {
    if(this == &srcS){
        return *this;
    }
    this->data = (int*)realloc(this->data, (size_t) sizeof(int) * srcS.allocatedMemory);
    assert(this->data);
    int current = 0;
    this->top = 0;
    while(current < srcS.top){
        this->push(srcS.data[current++]);
    }
    return *this;
}