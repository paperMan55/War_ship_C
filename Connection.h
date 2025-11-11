#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

 class Connection
{
    private:
        int clientSocket;
    public: 
        Connection(std::string ip_address, int port, bool& out_status);
        void close_c();
        bool send_m(const char* msg);
        bool send_m(std::string msg);

        std::string receive_m();
};

bool is_ip(const std::string& str);
#endif 
