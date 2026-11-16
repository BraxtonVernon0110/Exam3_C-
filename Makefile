all: baseball

baseball: main.o Player.o Events.o
	g++ main.o Player.o Events.o -o baseball 

main.o: main.cpp
	g++ -c main.cpp

Player.o: Player.cpp Player.cpp
	g++ -c Player.cpp

Events.o: Events.h Events.cpp
	g++ -c Events.cpp

clean: 
	rm -f *.o baseball