all: pacman

pacman-debug: pacman-debug.o Ambiente.o Quadrado.o Aresta.o Character.o functions.o Window.o InputInterface.o Debug.o
	g++ pacman.o functions.o Ambiente.o Character.o Window.o InputInterface.o Quadrado.o Aresta.o Debug.o -o pacman -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
	
pacman: pacman.o Ambiente.o Quadrado.o Aresta.o Character.o functions.o Window.o InputInterface.o
	g++ pacman.o functions.o Ambiente.o Character.o Window.o InputInterface.o Quadrado.o Aresta.o -o pacman -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi

##################################
# The game itself

pacman-debug.o: pacman.cpp headers/functions.h headers/Window.h headers/InputInterface.h headers/Ambiente.h headers/Debug.h
	g++ -fpermissive -c pacman.cpp -o pacman.o

pacman.o: pacman.cpp headers/functions.h headers/Window.h headers/InputInterface.h headers/Ambiente.h
	g++ -fpermissive -c pacman.cpp -o pacman.o

##################################
# OpenGL related

Window.o: Window.cpp headers/Window.h headers/Drawable.h headers/Inputable.h
	g++ -fpermissive -c Window.cpp -o Window.o

InputInterface.o: InputInterface.cpp headers/InputInterface.h headers/Window.h
	g++ -fpermissive -c InputInterface.cpp -o InputInterface.o

##################################
# Game related

CharacterInterface: headers/CharacterInterface.h headers/types.h

Character.o: Character.cpp headers/Character.h headers/Drawable.h headers/Inputable.h headers/functions.h
	g++ -fpermissive -c Character.cpp -o Character.o

##################################
# Global related

Debug.o: Debug.cpp headers/Debug.h
	g++ -fpermissive -c Debug.cpp -o Debug.o

functions.o: functions.cpp headers/functions.h
	g++ -fpermissive -c functions.cpp -o functions.o

##################################
# Maze related

Ambiente.o: Ambiente.cpp headers/Ambiente.h headers/Quadrado.h headers/Aresta.h headers/Character.h headers/CharacterInterface.h headers/Inputable.h headers/Drawable.h headers/functions.h
	g++ -fpermissive -c Ambiente.cpp -o Ambiente.o

Aresta.o: Aresta.cpp headers/Aresta.h headers/Quadrado.fwd.h
	g++ -fpermissive -c Aresta.cpp -o Aresta.o

Quadrado.o: Quadrado.cpp headers/Quadrado.h headers/Aresta.fwd.h headers/Drawable.h
	g++ -fpermissive -c Quadrado.cpp -o Quadrado.o

##################################
# Clean

clean:
	rm *.o
