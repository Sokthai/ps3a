all : ps3a
ps3a: main.o body.o
	g++ main.o body.o -o ps3a -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c main.cpp
body.o: body.cpp body.hpp
	g++ -c body.cpp
clean:
	rm *.o ps3a
