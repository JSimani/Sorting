# Josh Simani
# HW5
# March 27, 2017
# 
#  COMP 15 HW5
#  
#  Makefile
#  Written by: Josh Simani
#        UTLN: jsiman02
#          on: 3-27-17
# 

CXX      = clang++
CXXFLAGS = -g3 -O3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3 -O3

EXECUTABLES = sorter Testing/output

all: ${EXECUTABLES}

# Compiles the main sorter. You just have to type "make"
sorter: sorter.o sortAlgs.o wordWrap.o
	${CXX} ${LDFLAGS} -o sorter sorter.o sortAlgs.o wordWrap.o
sorter.o:	sorter.cpp sortAlgs.h 
sortAlgs.o: sortAlgs.cpp sortAlgs.h
wordWrap.o:	wordWrap.cpp wordWrap.h

Testing/output: Testing/output.o
	${CXX} ${LDFLAGS} -o Testing/output Testing/output.o
Testing/output.o:	Testing/output.cpp

# Cleans the current folder of all compiled files
clean:
	rm -rf ${EXECUTABLES} *.o *.dSYM Testing/*.o Testing/.*dSYM

# Checks the test program for sorter for possibly memory leaks
valgrind:
	valgrind ./sorter
