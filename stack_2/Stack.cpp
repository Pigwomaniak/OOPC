#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Stack::Stack(){
    top = 0;
    data = NULL;
    allocatedMemory = 0;
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
    if(top){
        return false;
    }
    return true;
}

Stack::~Stack() {
    free(data);
}