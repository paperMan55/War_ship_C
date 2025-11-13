#ifndef MAP_H
#define MAP_H
#include <iostream>



class Ship
{
    public:
    int x;
    int y;
    int length;
    bool horizontal;

    Ship(int xx, int yy, int length_, bool horizontal_);
};
class Map
{
    
    public:

    int map[10][10];
    Map();
    
    bool set_ship(int x, int y, int length, bool orientation);
};

std::ostream& operator<<(std::ostream& os, Map& r );


#endif