#ifndef SNAKE_H
#define SNAKE_H

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