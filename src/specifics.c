/*
 * specifics.c
 *
 *  Created on: Oct 24, 2015
 *      Author: dcipher
 */

#include "specifics.h"

bool correctArgs(char * arg)
{
	printf("start correctargs with arg:\n");
	printf("\"%s\"\n",arg);
	bool retVal = true;

	char client[3] = "-c\0";
	char server[3] = "-s\0";

	printf("length of %s is %lu\n",arg,strlen(arg));
	printf("length of %s is %lu\n",client,strlen(client));
	printf("length of %s is %lu\n",server,strlen(server));

	bool isClient = equalStrings(client,arg);
	bool isServer = equalStrings(server,arg);

	if(isClient)
	{
		printf("client\n");
	}
	else
	{
		printf("not client\n");
	}

	if(isServer)
	{
		printf("server\n");
	}
	else
	{
		printf("not server\n");
	}
	if(!isClient || !isServer)
	{
		retVal = false;
	}
	printf("end correctargs with arg:\"%s\"\n",arg);
	return retVal;
}

bool correctNumberOfArguments(int * pArgC)
{
	printf("start function correctNumberOfArguments\n");
	int correctNumArgs = 2; //for this program
	printf("end function correctNumberOfArguments\n");
	return (correctNumArgs == *pArgC);
}
