/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:56:11 by didimitr          #+#    #+#             */
/*   Updated: 2026/05/05 18:05:07 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/commands.hpp"

void commandExec(data data){
    switch (data.commandID)
    {
    case 1: handlePass(); break;
    case 2: handleNick(); break;    
    case 3: handleUser(); break;
    case 4: handlePrivmsg(); break;
    case 5: handleJoin(); break;
    case 6: handleKick(); break;
    case 7: handleInvite(); break;
    case 8: handleTopic(); break;
    case 9: handleMode(); break;
    
    default:
    {
        std::cerr << "Something" << std::endl;
        break;
    }
    }
}

void handlePass(void){

}
void handleNick(void){

}
void handleUser(void){

}
void handlePrivmsg(void){

}
void handleJoin(void){

}
void handleKick(void){

}
void handleInvite(void){

}
void handleTopic(void){

}
void handleMode(void){
    
}