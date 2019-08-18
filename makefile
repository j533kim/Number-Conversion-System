CC = gcc
CFLAGS = -Wall -g -std=c11

main: main_cal.o
	$(CC) main_cal.o -o Calculator
main_cal.o: main_cal.c
	$(CC) $(CFLAGS) -c main_cal.c -o main_cal.o
#run:
#	./Calculator
clean:
	@rm *.o Calculator