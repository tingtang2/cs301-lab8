# makefile
# use to compile and test the assembler ASM for the STACK computer and
# its various components

DEBUG_FLAG= -DDEBUG -g -Wall
CFLAGS=-DDEBUG -g -Wall

.SUFFIXES: .cpp .o

.cpp.o:
	g++ $(CFLAGS) -c $<


cachetest: driver.o Cache.o Set.o Block.o
	g++ -o cachetest driver.o Cache.o Set.o Block.o

Cache.o: Cache.h Set.h Block.h

Set.o: Set.h Block.h

Block.o: Block.h

clean:
	/bin/rm -f cachetest *.o core


