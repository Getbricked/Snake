#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <direct.h>
#include <SFML/Graphics.hpp>
#include "map.cpp"
using namespace sf;
using namespace std;


int main()
{
    Map m;
    Snake S;
    int direction = 0;
    CreateFood();
    while (window.isOpen()){

        Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();

        if(Keyboard::isKeyPressed(Keyboard::Left)) direction = 2;
        if(Keyboard::isKeyPressed(Keyboard::Up)) direction =  3;
        if(Keyboard::isKeyPressed(Keyboard::Right)) direction = 0;
        if(Keyboard::isKeyPressed(Keyboard::Down)) direction =  1;
        m.CreateMap(w, l, s);
        S.draw();
        S.movement(direction);
        S.eatfood();
        S.speedup(point);
        window.display();
        if(GameOver) window.close();
        if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
    }
    return 0;
}