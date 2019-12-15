# List your *.h files here:
headers = Employee.h Map.h

# List your *.cpp files here:
sources = TestMap.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind ./program

debug: program
	gdb program

