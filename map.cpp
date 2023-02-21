#include "map.h"
#include "setup.cpp"
#include "snake.cpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void Map::CreateMap(int w, int l, int s){
    Texture tred, twhite, tgreen;
    tred.loadFromFile("Data/red.png");
    twhite.loadFromFile("Data/white.png");
    tgreen.loadFromFile("Data/green.png");
    Sprite red(tred), white(twhite), green(tgreen);

        
    window.clear();
    
    for(int i = 0; i < w; i++){
        for(int j = 0; j < l; j++){

            if(i == 0 || i == w - 1){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }

            else if(j == 0 || j == l - 1){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }

            else if(i == foodX && j == foodY){
                red.setPosition(i*s, j*s);
                window.draw(red);
            }

            else{
                white.setPosition(i*s, j*s);
                window.draw(white);
            }

        }
    }

}