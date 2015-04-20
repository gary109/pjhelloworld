/* $Id: log.c 3553 2011-05-05 06:14:19Z nanang $ */
/*
 * Copyright (C) 2008-2011 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#include <stdio.h>
#include <stdlib.h>
#include <pjlib.h>
#include <pjlib-util.h>
#include <pjnath.h>
#include <pj/log.h>

#include "test.h"

int main()
{
	pj_status_t rc;
	// Error handling omited for clarity
	// Must initialize PJLIB first!
	rc = pj_init();
	
	PJ_LOG(3, ("main.c", "Hello world!"));
	while (1) {
		const char *SEP = " \t\r\n";
		char input[80], *cmd;
		pj_size_t len;

		printf("Input: ");
		pj_bzero(input, sizeof(input));
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		len = strlen(input);
		while (len && (input[len - 1] == '\r' || input[len - 1] == '\n'))
			input[--len] = '\0';

		cmd = strtok(input, SEP);
		if (!cmd)
			continue;

		if (strcmp(cmd, "q") == 0) {
			PJ_LOG(3, ("main.c", "Bye Bye.."));
			break;
		}else if (strcmp(cmd, "t") == 0) {
			PJ_LOG(3, ("main.c", "select test..."));
			select_test();
		}
		else if (strcmp(cmd, "x") == 0) {
			PJ_LOG(3, ("main.c", "send test..."));

			pj_sock_t udp1 = PJ_INVALID_SOCKET, udp2 = PJ_INVALID_SOCKET;
			pj_sockaddr_in udp_addr;
			int status;
			int setcount[3];
			pj_str_t s;
			const char data[] = "hello";
			const int datalen = 5;
			pj_ssize_t sent, received;
			char buf[10];
			pj_status_t rc;

			// Create two UDP sockets.
			rc = pj_sock_socket(pj_AF_INET(), pj_SOCK_DGRAM(), 0, &udp1);
			if (rc != PJ_SUCCESS) {
				//app_perror("...error: unable to create socket", rc);
				status = -10; goto on_return;
			}
			rc = pj_sock_socket(pj_AF_INET(), pj_SOCK_DGRAM(), 0, &udp2);
			if (udp2 == PJ_INVALID_SOCKET) {
				//app_perror("...error: unable to create socket", rc);
				status = -20; goto on_return;
			}
			// Bind one of the UDP socket.
			pj_bzero(&udp_addr, sizeof(udp_addr));
			udp_addr.sin_family = pj_AF_INET();
			udp_addr.sin_port = 55660;
			udp_addr.sin_addr = pj_inet_addr(pj_cstr(&s, "127.0.0.1"));
			if (pj_sock_bind(udp2, &udp_addr, sizeof(udp_addr))) {
				status = -30; goto on_return;
			}



		on_return:


		}



	}





	return 0;
}