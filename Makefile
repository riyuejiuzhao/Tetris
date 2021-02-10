game: game.cpp background.cpp background.h
	g++ game.cpp background.cpp -o game -Wall -I . -lncurses

clean:
	rm game