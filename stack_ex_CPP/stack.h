//
// Created by maciek on 24/10/2019.
//

#ifndef STACK_EX_CPP_STACK_H
#define STACK_EX_CPP_STACK_H

class Stack {
public:
    Stack();
    Stack(Stack* sourceS);
    ~Stack();
    void push(int element);
    int pop();
    bool isEmpty();
    Stack& operator=(Stack& srcS);

private:
    int top;
    int* data;
    int allocatedMemory;
};




#endif //STACK_EX_CPP_STACK_H
