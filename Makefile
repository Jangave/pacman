all: pacman

pacman-debug: pacman-debug.o functions.o Window.o InputInterface.o Character.o Debug.o
	g++ pacman.o functions.o Window.o InputInterface.o Character.o Debug.o -o pacman-debug -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
	
pacman: pacman.o functions.o Window.o InputInterface.o Character.o
	g++ pacman.o functions.o Window.o InputInterface.o Character.o -o pacman -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi

##################################

pacman-debug.o: pacman.cpp headers/functions.h headers/types.h headers/Window.h headers/InputInterface.h headers/Character.h headers/CharacterInterface.h headers/Drawable.h headers/Inputable.h headers/Debug.h
	g++ -fpermissive -c pacman.cpp -o pacman.o

pacman.o: pacman.cpp headers/functions.h headers/types.h headers/Window.h headers/InputInterface.h headers/Character.h headers/CharacterInterface.h headers/Drawable.h headers/Inputable.h
	g++ -fpermissive -c pacman.cpp -o pacman.o

##################################

Debug.o: Debug.cpp headers/Debug.h
	g++ -fpermissive -c Debug.cpp -o Debug.o

Window.o: Window.cpp headers/Window.h headers/Drawable.h headers/Inputable.h
	g++ -fpermissive -c Window.cpp -o Window.o

Character.o: Character.cpp headers/Character.h headers/CharacterInterface.h headers/Drawable.h headers/Inputable.h headers/types.h headers/functions.h
	g++ -fpermissive -c Character.cpp -o Character.o

InputInterface.o: InputInterface.cpp headers/InputInterface.h headers/Window.h
	g++ -fpermissive -c InputInterface.cpp -o InputInterface.o

functions.o: functions.cpp headers/functions.h headers/Window.h
	g++ -fpermissive -c functions.cpp -o functions.o

##################################



##################################

Ambiente.o: Ambiente.cpp headers/Ambiente.h headers/functions.h headers/Quadrado.h headers/Aresta.h
	g++ -fpermissive -c Ambiente.cpp -o Ambiente.o
Aresta.o: Aresta.cpp headers/Aresta.h headers/Quadrado.h
	g++ -fpermissive -c Aresta.cpp -o Aresta.o
Quadrado.o: Quadrado.cpp headers/Quadrado.h headers/Aresta.h
	g++ -fpermissive -c Quadrado.cpp -o Quadrado.o
clean:
	rm *.o
