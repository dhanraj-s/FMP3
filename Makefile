CC = g++
CFLAGS = -Wall
OBJS = main.o Channel.o Sound.o System.o musicPlayer.o
PROG = test
LOCALLIBDIR = /usr/local/lib
LDLIBS = -lfmod

all: $(PROG)

test: $(OBJS)
	$(CC) $(OBJS) -Wl,-rpath=$(LOCALLIBDIR) $(LDLIBS) -o $(PROG)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Channel.o: Channel.cpp
	$(CC) $(CFLAGS) -c Channel.cpp

Sound.o: Sound.cpp
	$(CC) $(CFLAGS) -c Sound.cpp

System.o: System.cpp
	$(CC) $(CFLAGS) -c System.cpp

musicPlayer.o: musicPlayer.cpp
	$(CC) $(CFLAGS) -c musicPlayer.cpp

clean:
	rm -rf *.o test