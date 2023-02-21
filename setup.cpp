#include "setup.h"
#include "snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


void CreateFood(){
    srand(time(NULL));
    foodX = rand() % (w - 1);
    foodY = rand() % (l - 1);
    while(foodX == 0 || foodY == 0){
        foodX = rand() % (w - 1);
        foodY = rand() % (l - 1);
    }
}

RenderWindow window(VideoMode(width, length), "Game");

void Snake::draw(){
    Texture tred;
    tred.loadFromFile("Data/red.png");
    Sprite red(tred);

    for(int i = 0; i < snake_size; i++){
        red.setPosition(A[i].x*s, A[i].y*s);
        window.draw(red);
    }
}