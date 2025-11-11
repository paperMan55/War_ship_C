#include "Map.h"


Map::Map(){
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            map[i][j] = 0;
        }
    }
}
bool Map::set_ship(int x, int y, int length, bool orientation){
    if(x<0 || y<0 || x>=10 || y>=10){return false;}
    
    if(orientation){
        if(x+length>10 ){
            return false;
        }
    }else{
        if(y+length>10 ){
            return false;
        }
    }

    for (size_t i = x; i < (orientation?x+1:x+length); i++)
    {
        for (size_t j = y; j < (orientation?y+length:y+1); j++)
        {
            if(map[i][j] == 2){
                return false;
            }
        }
    }
    for (size_t i = x; i < (orientation?x+1:x+length); i++)
    {
        for (size_t j = y; j < (orientation?y+length:y+1); j++)
        {
            map[i][j] = 2;
        }
    }
    

    return true;
}

std::ostream& operator<<(std::ostream& os, Map& r ){
    os<<"    0   1   2   3   4   5   6   7   8   9\n  +---+---+---+---+---+---+---+---+---+---+\n";
    for (size_t i = 0; i < 10; i++)
    {
        os << i<<" | ";
        for (size_t j = 0; j < 10; j++)
        {
            switch (r.map[i][j])
            {
            case 1:
                os << "\033[36m"<<r.map[i][j];
                break;
            case 2:
                
                os << "\033[32m"<<r.map[i][j];
                break;
            case 3:
                
                os << "\033[31m"<<r.map[i][j];
                break;
            
            default:
            os << r.map[i][j];
                break;
            }
            os <<"\033[0m | ";
        }
        os<<"\n  +---+---+---+---+---+---+---+---+---+---+\n";
        
    }
    
    return os ;
}