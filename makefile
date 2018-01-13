dealer: dealer.o  car.o  readline.o
	gcc -o dealer car.o dealer.o readline.o
dealer.o: dealer.c car.h readline.h
	gcc -c -Wall dealer.c
car.o: car.c car.h readline.h
	gcc -c -Wall car.c
readline.o: readline.c readline.h
	gcc -c -Wall readline.c  
