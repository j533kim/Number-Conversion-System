CC = gcc
CFLAGS = -Wall -g -std=c11

main: main_cal.o main_to_hexa.o main_to_deci.o main_to_binary.o
	$(CC) main_cal.o -o Calculator
main_cal.o: main_cal.c
	$(CC) $(CFLAGS) -c main_cal.c -o main_cal.o
main_to_hexa.o: main_to_hexa.c #main_to_deci.o
	$(CC) $(CFLAGS) -c main_to_hexa.c -o main_to_hexa.o
main_to_deci.o: main_to_deci.c
	$(CC) $(CFLAGS) -c main_to_deci.c -o main_to_deci.o
main_to_binary.o: main_to_binary.c
	$(CC) $(CFLAGS) -c main_to_binary.c -o main_to_binary.o
#run:
#	./Calculator
clean:
	@rm *.o Calculator


## Technical errors debugged