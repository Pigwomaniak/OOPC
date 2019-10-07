#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

#include "Stack.h"

int main(){
    Stack s;
    std::cout << "Is stack empty? : " << s.isEmpty() << "\n";
    s.push(0);
    s.push(1);
    s.push(2);
    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.pop() << "\n";
    return 0;
}

