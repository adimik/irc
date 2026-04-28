/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:48:12 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/28 11:25:58 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <vector>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

class Server {
    private:
        int _serverFd;
        int _port;
        std::string _password;
        std::vector<pollfd> _pollFds;
    public:
        Server(int port, const std::string &password);
        ~Server();

        void run();
        void initPoll();
        void initSocket();
        void acceptClient();
        void receiveFromClient(int fd);
};
