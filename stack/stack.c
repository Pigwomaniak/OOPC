#include "stack.h"
#include <stdio.h>
int main() {
	printf("hello\n");
	Stack s;
	init(&s);
	printf("Is empty stack: %d \n",(int)isEmpty(&s));
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("Is empty stack: %d \n",(int)isEmpty(&s));
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));
	printf("%d \n",pop(&s));
	destroy(&s);
	return 0;
}
