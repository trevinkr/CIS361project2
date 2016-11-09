
output: proj2.o list.o queue.o
	gcc proj2.o list.o queue.o -o output -g

proj2.o: proj2.c list.h list.c structure.h
	gcc -c proj2.c -g 

list.o: list.c list.h queue.c
	gcc -c list.c -g 

queue.o: queue.c queue.h
	gcc -c queue.c -g

clean:
	rm *.o output
