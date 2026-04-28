/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:48:15 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/28 11:31:00 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

Server::Server(int port, const std::string &password)
: _serverFd(-1), _port(port), _password(password)
{
}

Server::~Server() {
    
}

void Server::initSocket() {
    _serverFd = socket(AF_INET, SOCK_STREAM, 0);
    int yes = 1;
    if(_serverFd == -1)
    {
        std::cerr << "socket fail" << std::endl;
        return;
    }
    setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(_serverFd, (sockaddr*)&addr, sizeof(addr)) == -1)
    {
        std::cerr << "bind fail" << std::endl;
    }   
    std::cout << addr.sin_addr.s_addr << std::endl << addr.sin_family << std::endl << addr.sin_port << std::endl;
    if (listen(_serverFd, SOMAXCONN) == -1)
    {
        std::cerr << "listen failed" << std::endl;
        return;
    }
}

void Server::run() {
    
    initSocket();

    pollfd serverPoll;
    serverPoll.fd = _serverFd;
    serverPoll.events = POLLIN;
    serverPoll.revents = 0;
    _pollFds.push_back(serverPoll);
    
    while (true)
        {
            if (poll(&_pollFds[0], _pollFds.size(), -1) == -1)
            {
                std::cerr << "poll failed" << std::endl;
                return;
            }

            for (size_t i = 0; i < _pollFds.size(); ++i)
            {
                if (_pollFds[i].revents & POLLIN)
                {
                    if (_pollFds[i].fd == _serverFd)
                        acceptClient();
                    else
                        receiveFromClient(_pollFds[i].fd);
                }
            }
        }
}

void Server::acceptClient()
{
    int clientFd = accept(_serverFd, NULL, NULL);
    if (clientFd == -1)
    {
        std::cerr << "accept failed" << std::endl;
        return;
    }

    pollfd clientPoll;
    clientPoll.fd = clientFd;
    clientPoll.events = POLLIN;
    clientPoll.revents = 0;

    _pollFds.push_back(clientPoll);

    std::cout << "client accepted, fd = " << clientFd << std::endl;
}

void Server::receiveFromClient(int fd)
{
    (void)fd;
}