/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:57:58 by didimitr          #+#    #+#             */
/*   Updated: 2026/05/05 18:04:21 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "parser.hpp"

void commandExec(data data);
void handlePass(void);
void handleNick(void);
void handleUser(void);
void handlePrivmsg(void);
void handleJoin(void);
void handleKick(void);
void handleInvite(void);
void handleTopic(void);
void handleMode(void);