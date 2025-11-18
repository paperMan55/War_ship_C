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

    for (size_t i = y; i < (orientation?y+1:y+length); i++)
    {
        for (size_t j = x; j < (orientation?x+length:x+1); j++)
        {
            if(map[i][j] == 2){
                return false;
            }
        }
    }
    for (size_t i = y; i < (orientation?y+1:y+length); i++)
    {
        for (size_t j = x; j < (orientation?x+length:x+1); j++)
        {
            map[i][j] = 2;
        }
    }
    

    return true;
}
Ship::Ship(int xx, int yy, int length_, bool horizontal_):x{xx},y{yy},length{length_},horizontal{horizontal_}{
    
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
            case 1:  //acqua colpita
                os << "\033[36m"<<r.map[i][j];
                break;
            case 2:  //barca
                
                os << "\033[32m"<<r.map[i][j];
                break;
            case 3:  //barca colpita
                
                os << "\033[31m"<<r.map[i][j];
                break;
            
            default:   //acqua
            os << r.map[i][j];
                break;
            }
            os <<"\033[0m | ";
        }
        os<<"\n  +---+---+---+---+---+---+---+---+---+---+\n";
        
    }
    
    return os ;
}