game: *.cpp head/*.hpp
	g++ *.cpp -o game -Wall -I ./head -lncurses -lpthread -O3

debug: *.cpp head/*.hpp
	g++ *.cpp -o game -Wall -I ./head -lncurses -lpthread -g

clean:
	rm game