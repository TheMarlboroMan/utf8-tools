COMPILER=g++
DEBUG=-g
CFLAGS=-Wno-deprecated -Wall -ansi -pedantic -std=c++11 -Wfatal-errors
OBJD=obj/

all: objdir main.cpp $(OBJS)/utf8-tools.o
	$(COMPILER) $(CFLAGS) $(DEBUG) main.cpp $(OBJD)utf8-tools.o -o a.out

objdir:
	mkdir -p $(OBJD)

clean:
	rm $(OBJD)*; rmdir $(OBJD) rm ./a.out; echo "Clean";

$(OBJS)/utf8-tools.o: src/utf8-tools.h src/utf8-tools.cpp
	$(COMPILER) $(CFLAGS) $(DEBUG) -c src/utf8-tools.cpp -o $(OBJD)utf8-tools.o
