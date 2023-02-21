#include "snake.h"
#include "setup.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


Snake::Snake(){
    snake_size = 3;
    A[0].x = w/2; A[0].y = l/2;
    A[1].x = w/2 + 1; A[1].y = l/2;
    A[2].x = w/2 + 1; A[2].y = l/2;
}


void Snake::movement(int direction){
    for(int i = snake_size - 1; i > 0; i--)
        A[i] = A[i-1];

    for(int i = 2; i < snake_size + 1; i++)
        if(A[0].x == A[i].x && A[0].y == A[i].y)
            GameOver = true;

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

void Snake::eatfood(){
    if(A[0].x == foodX && A[0].y == foodY){
        snake_size++;
        point++;
        srand(time(NULL));
        CreateFood();
    }
}

void Snake::speedup(int point){
    window.setFramerateLimit(10+(point/5));
}
