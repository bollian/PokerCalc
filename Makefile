CC = gcc
o_path = bin/
lib_path = lib/
#pro_path = $(shell pwd)
flags = -std=c99 -c -I.
test_path = test/

all: $(o_path) $(lib_path) Card.o Hand.o Calc.o
	ar -cvr $(lib_path)/libPokerCalc.a $(o_path)/*.o
	cd $(test_path); make

clean:
	rm -rf $(o_path) $(lib_path)

rebuild: clean
	make all

Card.o: $(o_path) Card.c Card.h
	$(CC) Card.c $(flags) -o $(o_path)/Card.o

Hand.o: $(o_path) Hand.c Hand.h
	$(CC) Hand.c $(flags) -o $(o_path)/Hand.o

Calc.o: $(o_path) Calc.c Calc.h
	$(CC) Calc.c $(flags) -o $(o_path)/Calc.o

$(o_path):
	mkdir $(o_path)

$(lib_path):
	mkdir $(lib_path)