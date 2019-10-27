#include "Stack.h"
#include <stdlib.h>
#include <iostream>
#include <stdbool.h>

Stack::Stack(){
    top = 0;
    data = nullptr;
    allocatedMemory = 0;
}

void Stack::push(int element) {
    if(allocatedMemory <= top){
        if(allocatedMemory == 0){
            allocatedMemory = 1;
        } else{
            allocatedMemory *= 5;
        }
        if(!(data = (int *)realloc(data, (allocatedMemory) * sizeof(int)))) {
            std::cout << "realloc fail";
            exit(0);
        }
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
    if(top){
        return false;
    }
    return true;
}

Stack::~Stack() {
    free(data);
}