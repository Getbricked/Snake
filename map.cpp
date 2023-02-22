#include "map.h"
#include "setup.cpp"
#include "snake.cpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

// CreateMap fuction
void Map::CreateMap(int w, int l, int s){

    // Import texture for the sprite
    Texture tred, twhite, tgreen;
    tred.loadFromFile("Data/red.png");
    twhite.loadFromFile("Data/white.png");
    tgreen.loadFromFile("Data/green.png");
    Sprite red(tred), white(twhite), green(tgreen);
    

    // This loop using to draw the map
    for(int i = 0; i < w; i++){
        for(int j = 0; j < l; j++){
            
            // Draw the border
            if(i == 0 || i == w - 1){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }
            else if(j == 0 || j == l - 1){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }


            // Draw the food
            else if(i == foodX && j == foodY){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }

            // Draw the blocks inside border
            else{
                white.setPosition(i*s, j*s);
                window.draw(white);
            }

        }
    }

}