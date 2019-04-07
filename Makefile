CC = g++
CFLAGS = -Wall
OBJS = musicSystem.o Channel.o Sound.o System.o
PROG = test
LOCALLIBDIR = /usr/local/lib
LDLIBS = -lfmod

all: $(PROG)

test: $(OBJS)
	$(CC) $(OBJS) -Wl,-rpath=$(LOCALLIBDIR) $(LDLIBS) -o $(PROG)

musicSystem.o: musicSystem.cpp
	$(CC) $(CFLAGS) -c musicSystem.cpp

Channel.o: Channel.cpp
	$(CC) $(CFLAGS) -c Channel.cpp

Sound.o: Sound.cpp
	$(CC) $(CFLAGS) -c Sound.cpp

System.o: System.cpp
	$(CC) $(CFLAGS) -c System.cpp

clean:
	rm -rf *.o test