
CFLAGS := -g -Wall 
all:  tests_ecosys ecosys

ecosys.o: ecosys.c ecosys.h
	gcc $(CFLAGS) -c ecosys.c

main_tests.o : main_tests.c
	gcc $(CFLAGS) -c main_tests.c

tests_ecosys	: ecosys.o main_tests.o
	gcc $(CFLAGS) -o test_ecosys ecosys.o main_tests.o

main_ecosys.o : main_ecosys.c
	gcc $(CFLAGS) -c main_ecosys.c 

ecosys : main_ecosys.o ecosys.o
	gcc $(CFLAGS) -o ecosys ecosys.o main_ecosys.o

#Separation

clean:
	rm -f *.o *~ $(PROGRAMS)
