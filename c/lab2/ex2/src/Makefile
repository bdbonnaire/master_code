CC = g++
CXXFLAGS = -I../include
SRCS = trip.cpp tripmain.cpp date.cpp 
OBJS = $(SRCS:.cpp=.o)
EXEC = ../bin

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean : 
	@echo "Object files are removed ..."
	rm $(OBJS)
