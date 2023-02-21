all: compile link run

compile:
	g++ -c main.cpp -I"Data\SFML-2.5.1\include" -DSFML_STATIC
	g++ main.o -o main -L"Data\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

link:
	g++ main.o -o main -L"Data\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
