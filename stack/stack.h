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


void init(Stack *s){
	s->data = NULL;
	s->top = 0;
	s->allocatedMemory = 0;
}
void destroy(Stack* s){
	free(s->data);
}
void push(Stack* s, int element){
	if(s->top >= s->allocatedMemory){
	    int *temp;
		if(!(temp = realloc(s->data, (size_t)((s->allocatedMemory + 5) * sizeof(int))))){
		    printf("realloc fail");
		    exit(0);
		}
		s->data = temp;
		s->allocatedMemory += 5;
	}
	s->data[s->top] = element;
	s->top++;
}
int pop(Stack* s){
	if(s->top){
	    return s->data[--(s->top)];
	}
	printf("Empty stack    ");
	return 0;
}
bool isEmpty(Stack* s){
	if(s->top){
		return 0;
	}
	return 1;
}
