bin_dir = bin
CC = gcc
flags = -std=c99 -I.. -L../lib -lPokerCalc

all: $(bin_dir) Card Hand Calc
	

clean:
	rm -rf bin

rebuild: clean
	make all

Card: $(bin_dir) Card.c
	$(CC) Card.c -o $(bin_dir)/card $(flags)

Hand: $(bin_dir) Hand.c
	$(CC) Hand.c -o $(bin_dir)/hand $(flags)

Calc: $(bin_dir) Calc.c
	$(CC) Calc.c -o $(bin_dir)/calc $(flags)

$(bin_dir):
	mkdir $(bin_dir)