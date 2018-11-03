all:Game

Game:Board.o Game.o 
	g++ -o Game Board.o Game.o main.cpp
Game.o:Game.cpp
	g++ -c Game.cpp
Board.o:Board.cpp
	g++ -c Board.cpp
clean:  
	rm *.o