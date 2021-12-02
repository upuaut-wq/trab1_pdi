LIB = include 

all: exe_arq

exe_arq: main.o
	g++ -o exe_arq main.o

main.o: main.cpp
	mkoctfile --link-stand-alone -o main.o main.cpp -c `pkg-config --cflags --libs octave`