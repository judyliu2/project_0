all: tunes.o main.o
	gcc -o tester tunes.o main.o

tunes.o: tunes.c headers.h
	gcc -c tunes.c

main.o: main.c headers.h
	gcc -c main.c

clean: 
	rm *.o
	rm *~

run: all
	./tester
