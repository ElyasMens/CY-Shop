exec : Main.o Account.o Stockage.o Visuel.o
	gcc -o exec Main.o Account.o Stockage.o Visuel.o

Main.o : Main.c
	gcc -o Main.o -c Main.c

Account.o : Account.c
	gcc -o Account.o -c Account.c

Stockage.o : Stockage.c
	gcc -o Stockage.o -c Stockage.c

Visuel.o : Visuel.c
	gcc -o Visuel.o -c Visuel.c


clean :
	rm *.o exec