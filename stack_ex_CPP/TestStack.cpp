#include <iostream>
#include "stack.h"
#include <cassert>

#define NUMBER_OF_ELEMENTS 6
using namespace std;

int main() {
    cout << "Test stack" << endl;
    Stack first;
    for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
        first.push(i);
    }
    Stack second (&first);
    while(!first.isEmpty()){
        int current1 = first.pop();
        int current2 = second.pop();
        //cout << current1 << " = " << current2 << endl;
        assert(current1 == current2);
    }
    cout << "initialization OK" << endl;
    for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {
        first.push(i);
    }
    Stack third (&first);
    third.push(NUMBER_OF_ELEMENTS);
    third = first;
    while (!(third.isEmpty())){
        int current1 = first.pop();
        int current3 = third.pop();
        //cout << current1 << " = " << current3 << endl;
        assert(current1 == current3);
    }
    cout << "assigment OK" << endl;
    return 0;
}
