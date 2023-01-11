SFMLpath ?= SfmlPath 

all: SoftBody

SoftBody: Source.o Graphics.o Point.o Block.o
	g++ Source.o Graphics.o Point.o Block.o -o prog -I$(SFMLpath)/include -L$(SFMLpath)/lib -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

Source.o: Source.cpp
	g++ -c Source.cpp --std c++20

Graphics.o: Graphics.cpp
	g++ -c Graphics.cpp --std c++20

Point.o: Point.cpp
	g++ -c Point.cpp --std c++20

Block.o: Block.cpp
	g++ -c Block.cpp --std c++20

