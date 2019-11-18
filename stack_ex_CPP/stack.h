#pragma once

class Stack {
public:
    Stack();
    explicit Stack(Stack* sourceS);
    ~Stack();
    void push(int element);
    int pop();
    bool isEmpty();
    Stack& operator=(const Stack& srcS);

private:
    int top;
    int* data;
    int allocatedMemory;
};
