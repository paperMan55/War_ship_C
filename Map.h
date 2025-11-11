#ifndef MAP_H
#define MAP_H
#include <iostream>

class Map
{
    
public:

    int map[10][10];
    Map();
    
    bool set_ship(int x, int y, int length, bool orientation);
};
std::ostream& operator<<(std::ostream& os, Map& r );


#endif