#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

 class Connection
{
    private:
        int clientSocket;
    public: 
        bool connect_s(std::string ip_address, int port);
        void close_c();
        bool send_m(const char* msg);
        bool send_m(std::string msg);

        std::string receive_m();
};

bool is_ip(const std::string& str);
#endif 
