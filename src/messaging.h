#ifndef MESSAGING_H
#define MESSAGING_H

#include <stdio.h>
#include <string>
#include <vector>
#include "strsplit.h"
#include "handlers.h"
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

#define AUTH_PORT 1818
#define BUFLEN 512
#define CPPCONN_PUBLIC_FUNC
#define SERVER "127.0.0.1"

const int MSG_LOGIN_RESPONSE     = 10001;
const int MSG_CHARACTER_LIST     = 10002;
const int MSG_UPDATE_WORLD       = 10003;
const int MSG_CHARDATA           = 10004;
const int MSG_REQUEST_CHARDATA   = 10005;

struct sockaddr_in si_other;
int s, slen=sizeof(si_other);
char buf[BUFLEN];
char message[BUFLEN];
WSADATA wsa;

std::string Handle(std::string str)
{ 
	std::vector<std::string> strs = split(str, ':');
	int id = stoi(strs[0]);
	std::string data = strs[1];

	switch(id)
	{
		case MSG_LOGIN_RESPONSE:     return(H_MSG_LOGIN_RESPONSE(data));     break;
		case MSG_CHARACTER_LIST:     return("test");     break; //RETURN VECTOR OF CHARACTERS
	}
}

std::vector<std::string> HandleV (std::string str)
{
	std::vector<std::string> strs = split(str, ':');
	int id = stoi(strs[0]);
	std::string data = strs[1];

	switch(id)
	{
		case MSG_CHARACTER_LIST:     return(H_MSG_CHARACTER_LIST(data));     break; //RETURN VECTOR OF CHARACTERS
	}
}

void Send(long long id, std::vector<std::string> data)
{
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(AUTH_PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	std::string str;
	std::vector<std::string>::iterator it;
	int count = 0;
	for (it = data.begin(); it != data.end(); ++it )
	{
		count++;
		if (count==1)
			str += std::to_string(id) + ":" + *it;
		else
			str += "," + *it;
	}
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	printf("Initialised.\n");
	//create socket
	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
         
	//send the message
	if (sendto(s, str.c_str(), str.size() , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

void Receive()
{
	memset(buf,'\0', BUFLEN);
	if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
	{
		printf("recvfrom() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

#endif