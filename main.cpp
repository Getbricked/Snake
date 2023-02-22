#include <iostream>
#include <time.h>
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
    bool check = true;

    // This loop to open the window
    while (window.isOpen()){

        Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();

        // Keyboard input to change direction
        if(Keyboard::isKeyPressed(Keyboard::Left)) direction = 2;
        if(Keyboard::isKeyPressed(Keyboard::Up)) direction =  3;
        if(Keyboard::isKeyPressed(Keyboard::Right)) direction = 0;
        if(Keyboard::isKeyPressed(Keyboard::Down)) direction =  1;
        
        // Create the map and draw the snake
        m.CreateMap(w, l, s);
        S.draw();


        // Using space as pause key!
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            if(check)
                check = false;
            else
                check = true;
        }
        if(check){
            //Snake's movement and eating food
            S.movement(direction);
            S.eatfood();
            S.speedup(point);   
        }

        // Display the window
        window.display();
        
        // Auto close the game if gameover or pressing esc
        if(GameOver) 
            window.close();   
        if(Keyboard::isKeyPressed(Keyboard::Escape)) 
            window.close();

    }
    return 0;
}