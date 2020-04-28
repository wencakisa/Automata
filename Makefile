OBJECTS = *.cpp
EXEC = automata.out
FLAGS = -Wall -std=c++11
CC = g++

all: $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)

clean:
	rm $(EXEC)
