#include <iostream>
#include <assert.h>
#include "Stack.h"
using namespace std;
int main(){
    Stack s1;
    assert(s1.isEmpty());
    for (int i = 0; i < 5; ++i) {
        s1.push(i);
    }
    assert(!s1.isEmpty());
    for (int i = 0; i < 5; ++i) {
        assert(s1.pop() != (5 - i));
    }
    cout << "Test complite" << endl;
    return 0;
}

