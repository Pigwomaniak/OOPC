# List your *.h files here:
headers = ComplexNum.h

# List your *.cpp files here:
sources = ComplexNum.cpp TestComplexNum.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind ./program

debug: program
	gdb program
