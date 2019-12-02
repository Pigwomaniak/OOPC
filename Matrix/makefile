# List your *.h files here:
headers = Matrix.h Cref.h

# List your *.cpp files here:
sources = Matrix.cpp TestMatrix.cpp Cref.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind ./program

debug: program
	gdb program

