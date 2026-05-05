/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:13:07 by didimitr          #+#    #+#             */
/*   Updated: 2026/05/05 15:54:37 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>


struct data
{
    std::string command;
    std::vector<std::string> param;
    int commandID;
};

void processMessage(int client_fd, std::string message);
data parse(std::string message);
bool inputValidation(data data);
std::string toUpper(const std::string& input);
void execCommand(data data);
int commandParse(std::string &str);