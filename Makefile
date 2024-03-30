# Define the object files
objects = main.o graph.o entry.o dijkstra.o

# The default target prog
# is the name of the executable file
prog: $(objects)
	gcc $(objects) -o prog

# Individual dependencies
main.o: main.c graph.h
	gcc -c main.c
graph.o: graph.c graph.h
	gcc -c graph.c
entry.o: entry.c graph.h
	gcc -c entry.c
dijkstra.o: dijkstra.c graph.h
	gcc -c dijkstra.c

# Clean up
clean:
	rm -rf *.o prog