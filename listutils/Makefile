CC = gcc
INCL = -I../include
DEPS = listutils.o

listutils.o: ../include/listutils.h listutils.c
	$(CC) $(INCL) -c listutils.c

test: listutils.o listutilsTest.c
	$(CC) $(INCL) -o tests listutilsTest.c $(DEPS)

run_test: test
	./tests
	rm tests *.o	
