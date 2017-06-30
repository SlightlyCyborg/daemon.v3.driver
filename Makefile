all: main.cpp
	g++ -Wall -pthread -o daemon main.cpp -lncurses -lpigpio -lrt
