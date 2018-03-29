# Makefile

CXX=g++
EXFLAGS=
FLAGS=-Wall -std=c++14 $(EXFLAGS)
DEPS=Exceptions.hpp Matriz.hpp
OBJ=Main.o Exceptions.o Matriz.o

main: $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o Main

%.o: %.cpp $(DEPS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) *.o
	
all: main

