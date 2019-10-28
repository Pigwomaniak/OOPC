#pragma once

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
