all: stack

stack: stack.o stack.o
	gcc -g $^ -o $@ -lm -lSDL -lpthread -lSDL_gfx

.c.o: 
	gcc -g -Wall -pedantic -std=c99 -c -D_REENTRANT $<

stack.o: stack.c stack.h

stack.o: stack.c stack.h

clean:
	-rm stack.o stack.o stack
