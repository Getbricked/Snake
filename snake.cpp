#include "snake.h"
#include "setup.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

// Setup the default coordinate of the snake: at the middle
Snake::Snake(){
    snake_size = 3;
    A[0].x = w/2; A[0].y = l/2;
    A[1].x = w/2 + 1; A[1].y = l/2;
    A[2].x = w/2 + 1; A[2].y = l/2;
}

// Snake's movement function with game over condition
void Snake::movement(int direction){

    // Passing the coordinate of the current box to the previous one so the snake will move
    for(int i = snake_size - 1; i > 0; i--)
        A[i] = A[i-1];

    // If the snake collides to the body part game over
    for(int i = 2; i < snake_size + 1; i++)
        if(A[0].x == A[i].x && A[0].y == A[i].y)
            GameOver = true;

    // Condition of direction : If the snake doesn't hit the border then its coordinate will be updated
    if(direction == 0){
        if(A[0].x > l - 3){
            GameOver = true;
        }

        else
            A[0].x = A[0].x + 1;
    }

    if(direction == 1){
        if(A[0].y > w - 3){
            GameOver = true;
        }

        else
            A[0].y = A[0].y + 1;
    }

    if(direction == 2){
        if(A[0].x < 2){
            GameOver = true;
        }

        else
            A[0].x = A[0].x - 1;
    }  

    if(direction == 3){
        if(A[0].y < 2){
            GameOver = true;
        }

        else
            A[0].y = A[0].y - 1;
    }  
}

// Eat food function
void Snake::eatfood(){

    // If head's coordinate equal to the coordinate of the food then increase snake size, point and generate a new food
    if(A[0].x == foodX && A[0].y == foodY){
        snake_size++;
        point++;
        srand(time(NULL));
        CreateFood();
    }
}

// Control the speed of the snake using frame rate limit
void Snake::speedup(int point){
    window.setFramerateLimit(10+(point/5));
}
