CC = g++
CFLAGS = -g -Wall -Werror -std=c++0x -pedantic
SFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost = -lboost_unit_test_framework

all:	TextGenerator mmtest

TextGenerator:	TextGenerator.o MarkovModel.o
	$(CC) TextGenerator.o MarkovModel.o -o TextGenerator

mmtest:	mmtest.o MarkovModel.o
	$(CC) mmtest.o MarkovModel.o -o mmtest $(Boost)

TextGenerator.o:TextGenerator.cpp MarkovModel.hpp
	$(CC) -c TextGenerator.cpp MarkovModel.hpp $(CFLAGS)

MarkovModel.o:MarkovModel.cpp MarkovModel.hpp
	$(CC) -c MarkovModel.cpp  MarkovModel.hpp $(CFLAGS)

mmtest.o:mmtest.cpp
	$(CC) -c mmtest.cpp $(Boost)

clean:
	rm *.o
	rm *.gch
	rm TextGenerator
	rm mmtest
