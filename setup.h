#ifndef SETUP_H
#define SETUP_H

#include <SFML/Graphics.hpp>

const int w = 50;
const int l = 50;
const int s = 15;

int foodX;
int foodY;

void CreateFood();

bool GameOver = false;

int width = w * s;
int length = l * s;

int point = 0;


#endif