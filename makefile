CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=LinList.cpp LinListTst.cpp ListDialog.cpp ListElement.cpp
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: cppreader
cppreader: main.o cppreader.o  
	$(CXX) $(CPPFLAGS) -o cppreader main.o cppreader.o
main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp
cppreader.o: cppreader.cpp cppreader.h
	$(CXX) $(CPPFLAGS) -c cppreader.cpp

.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch