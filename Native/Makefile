cc=gcc

main:main.o add.o
	$(cc) -o main main.o add.o

main.o:main.c
	$(cc) -c -o main.o main.c

add.o:add.c
	$(cc) -c -o add.o add.c

clean:
	rm -f *.o main