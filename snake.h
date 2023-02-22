#ifndef SNAKE_H
#define SNAKE_H

// This struct using to set the cordinates of the snake
struct Point {
    int x;
    int y;
};


class Snake{
public:
    Point A[100];
    int snake_size;
    Snake();
    void draw();
    void movement(int direction);
    void eatfood();
    void speedup(int point);
};

#endif