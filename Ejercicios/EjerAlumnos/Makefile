programa: main.o libreria.o
	gcc -o programa main.o libreria.o
main.o: main.c libreria.c
	gcc -c main.c
funciones.o: libreria.c libreria.o
	gcc -c libreria.c
clean:
	rm -f programa *.o