#include "Connection.h"
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

Connection::Connection(std::string ip_address, int port, bool& out_status)
{ 
    std::cout  << "\033[32mConnecting to "<<ip_address<<"\033[0m\n";
    clientSocket = socket(AF_INET, SOCK_STREAM,0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_pton(AF_INET, ip_address.c_str(), &serverAddress.sin_addr);

    int st =connect(clientSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
    out_status = (st == 0);
}

void Connection::close_c(){
    close(clientSocket);
}
bool Connection::send_m( const char* msg){
    return send(clientSocket,msg,strlen(msg),0);
}
bool Connection::send_m( std::string msg){
    return send(clientSocket,msg.c_str(),strlen(msg.c_str()),0);
}
std::string Connection::receive_m(){
    char buffer[1024];
    
    int val = read(clientSocket,buffer, 1024);
    std::string msg = buffer;
    return msg;
}
bool is_ip(const std::string& str){
    int points = 0;
    std::string num;
    for (size_t i = 0; i < str.length(); i++)
    {
        if(str.at(i) == 46){  // 46 = .
            try
            {
                int a = std::stoi(num);
            }
            catch(const std::exception& e)
            {
                return false;
            }
            num = "";
            points ++;
        }else{
            num.append(1,str.at(i));
        }
    }
    if (points != 3)
    {
        return false;
    }
    return true;
    
}

