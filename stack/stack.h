#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int top;
	int *data;
	int allocatedMemory;
} Stack;

void init(Stack *s);
void destroy(Stack *s);
void push(Stack *s, int element);
int pop(Stack *s);
bool isEmpty(Stack *s);