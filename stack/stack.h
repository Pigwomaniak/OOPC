#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int top;
	int *data;
	int alocatedMemory;
} Stack

void init(struct Stack* s)
void destroy(struct Stack* s)
void push(struct Stack* s, int element)
int pop(struct Stack* s)
bool isEmpty(struct Stack* s)


void init(struct Stack* s){
	s->data = NULL;
	s->top = 0;
	s->alocatedMemory = 0;
}
void destroy(struct Stack* s){
	free(s);
}
void push(struct Stack* s, int element){
	if(s->top >= s->alocatedMemory){
		realloc(s->data, (size_t)(5 * sizeof(int)));
		s->alocatedMemory += 5;
	}
	*(s->data + top)
}
int pop(struct Stack* s){
	
}
bool isEmpty(struct Stack* s){
	if(s->top){
		return 0;
	}
	return 1;
}
