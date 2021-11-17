programa: main.o prueba.o
	gcc -o programa main.o prueba.o
main.o: main.c prueba.h
	gcc -c main.c 
prueba.o: prueba.c prueba.h
	gcc -c prueba.c
clean:
	rm -f programa *.o
	