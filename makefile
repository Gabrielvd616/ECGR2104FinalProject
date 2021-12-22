all: Player.o gameEngine.o
	g++ Player.o gameEngine.o treasure.cpp -o treasure
gameEngine.o: gameEngine.cpp
	g++ gameEngine.cpp -c
Player.o: Player.cpp
	g++ Player.cpp -c
clean:
	rm Player.o gameEngine.o
realclean:
	rm treasure
