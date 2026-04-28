/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:46:13 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/28 11:25:31 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    Server server(std::atoi(argv[1]), argv[2]);
    server.run();
    return(0);
}