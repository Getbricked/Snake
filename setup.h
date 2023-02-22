#ifndef SETUP_H
#define SETUP_H

#include <SFML/Graphics.hpp>


// This is setup s = 15 because the input png file is 16x16 pixels (-1 to clear the black border)
const int w = 50;
const int l = 50;
const int s = 15;

// Coordinate of the food
int foodX;
int foodY;

// Function to create the food
void CreateFood();

bool GameOver = false;

// Width and Length of the window in pixels
int width = w * s;
int length = l * s;

// Point to control snake's speed
int point = 0;


#endif