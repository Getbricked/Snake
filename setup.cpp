#include "setup.h"
#include "snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


// CreateFood function
void CreateFood(){

    // Random coordinate
    srand(time(NULL));
    foodX = rand() % (w - 1);
    foodY = rand() % (l - 1);

    // Random again if the food spawn in the border
    while(foodX == 0 || foodY == 0){
        foodX = rand() % (w - 1);
        foodY = rand() % (l - 1);
    }
}


// Create the window
RenderWindow window(VideoMode(width, length), "Game");

// Draw the snake
void Snake::draw(){

    // Import texture
    Texture tred;
    tred.loadFromFile("Data/red.png");
    Sprite red(tred);

    // Draw the snake in the window
    for(int i = 0; i < snake_size; i++){
        red.setPosition(A[i].x*s, A[i].y*s);
        window.draw(red);
    }
}