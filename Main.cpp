#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include "Connection.h"
#include "Map.h"


Connection try_connect(){
    
    
    
    while (true)
    {
        std::cout << "server ip address: ";
        std::string ip;
        std::cin >> ip;
        std::cout << "server port: ";
        
        std::string port;
        std::cin >> port;

        bool status = false;
        try
        {

            if(is_ip(ip)){

                Connection conn(ip,std::stoi(port),status);

                if(status){
                    return conn;
                }else{
                    std::cout << "\033[31merror trying to connect to \033[0m"<<ip<<":"<<port<<" \033[31m  *try again*\n\t\tCANT FIND\033[0m\n";
                }
            }else{
                std::cout << "\033[31merror trying to connect to \033[0m"<<ip<<":"<<port<<" \033[31m  *try again*\n\t\tBAD IP\033[0m\n";

            }
            
        }
        catch(const std::exception& e)
        {
            std::cout  << "\033[31merror trying to connect to \033[0m"<<ip<<":"<<port<<" \033[31m  *try again*\n\t\tBAD PORT\033[0m\n";
        }
        
        

        
        
        

    }
}

void setup_ships(Map& map){
    int ships[]{2,3,3,4,5};
    
    for (size_t i = 0; i < sizeof(ships)/sizeof(ships[0]); i++)
    {   
        int x = 0;
        int y = 0;
        bool orientation = true;
        std::cout << "where do you want your ship("<<ships[i]<<") ?\n\tx: ";
        std::cin >>x;
        std::cout << "\ty: ";
        std::cin >>y;
        std::cout << "\tis it horizontal? (y/z)\t";
        std::string tmp;
        std::cin >>tmp;
        orientation = tmp == "y";
        bool can = map.set_ship(x,y,ships[i],orientation);
        if(!can){
            std::cout << "cant place there, retry.\n";
            i--;
        }else{
            std::cout << map;
        }
    }

    
}


int main(){
    Map a;
    
    std::cout << a;
    
    Connection connection = try_connect();

    while (true)
    {
        std::string msg;
        std::cin >> msg;
        connection.send_m(msg);
    }
    

    return 1;
}



