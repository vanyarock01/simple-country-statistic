CC = g++
FLAGS = -std=c++11 -O2 -pedantic -Wall -Wno-sign-compare -Wno-long-long -lm
FILES = country.cpp main.cpp 
PROG = prog
index:
    $(CC) $(FLAGS) -o $(PROG) $(FILES)

clean:
    rm -f *.o prog