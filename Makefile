# Define the object files
objects = main.o graph.o entry.o shortestPaths.o

# The default target prog
# is the name of the executable file
prog: $(objects)
	gcc $(objects) -o prog

# Individual dependencies
main.o: main.c graph.h entry.h shortestPaths.h
	gcc -c main.c
graph.o: graph.c graph.h
	gcc -c graph.c
entry.o: entry.c entry.h
	gcc -c entry.c
shortestPaths.o: shortestPaths.c shortestPaths.h
	gcc -c shortestPaths.c

# Clean up
clean:
	rm -rf *.o prog