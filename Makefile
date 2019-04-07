all: test

test: musicSystem.o Channel.o Sound.o System.o
	g++ musicSystem.o Channel.o Sound.o System.o -Wl,-rpath=/usr/local/lib -lfmod -o test

musicSystem.o: musicSystem.cpp
	g++ -c musicSystem.cpp

Channel.o: Channel.cpp
	g++ -c Channel.cpp

Sound.o: Sound.cpp
	g++ -c Sound.cpp

System.o: System.cpp
	g++ -c System.cpp

clean:
	rm -rf *.o 