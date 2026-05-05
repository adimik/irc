/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:13:10 by didimitr          #+#    #+#             */
/*   Updated: 2026/05/05 18:05:33 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.hpp"

int commandParse(std::string &str){
    if(str == "PASS") return(1);
    else if (str == "NICK") return(2);
    else if (str == "USER") return(3);
    else if (str == "PRIVMSG") return(4);
    else if (str == "JOIN") return(5);
    else if (str == "KICK") return(6);
    else if (str == "INVITE") return(7);
    else if (str == "TOPIC") return(8);
    else if (str == "MODE") return(9);
    else return(0);
}

void processMessage(int client_fd, std::string message) {
    
    data data = parse(message);
    if(!inputValidation(data))
    {
        //dunno, do something
        return;
    }
    std::cout << "Command: \"" << data.command << "\"" << std::endl;
    for (size_t i = 0; i < data.param.size(); ++i) {
        std::cout << "Parameter: \"" <<data.param[i] << "\"" << std::endl;
    }
    
    (void)client_fd;
}

std::string toUpper(const std::string& input) {
    std::string result = input;

    for (std::string::size_type i = 0; i < result.size(); ++i) {
        result[i] = std::toupper(static_cast<unsigned char>(result[i]));
    }

    return result;
}

data parse(std::string message) {
    data result;
    result.commandID = 0;
    size_t space = message.find(' ');
    result.command = message.substr(0, space);
    result.command = toUpper(result.command);
    if (space == std::string::npos || result.command.empty())
        return result;
    std::string rest = message.substr(space + 1);

    while (!rest.empty()) {
        if (rest[0] == ':') {
            result.param.push_back(rest.substr(1));
            break;
        }
        size_t s = rest.find(' ');
        if(!rest.empty())
            result.param.push_back(rest.substr(0, s));
        if (s == std::string::npos) break;
        rest = rest.substr(s + 1);
    }
    result.commandID = commandParse(result.command);
    return result;
}

bool inputValidation(data data){
    if(data.command.empty() || data.commandID == 0)
    {
        std::cerr << "Error unknown command: \"" << data.command << "\"" << std::endl;
        return(false);
    }
    return(true);    
}

