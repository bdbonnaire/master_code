CC = g++
CXXFLAGS = -I../include -g
SRCS = factorial.cpp mycollection.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = ../bin

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean : 
	@echo "Object files are removed ..."
	rm $(OBJS)

doc : Doxyfile
	doxygen Doxyfile

Doxyfile :
	doxygen -g Doxyfile
