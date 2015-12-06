/*
 * specifics.h
 *
 *  Created on: Oct 24, 2015
 *      Author: dcipher
 */

#ifndef SRC_SPECIFICS_H_
#define SRC_SPECIFICS_H_

#include <stdio.h>
 // for printf(), scanf(), NULL, FILE, fopen()
#include <unistd.h>
 // for sleep()
#include <stdbool.h>
 // for bool type
#include <stdlib.h>
 // for malloc() & free()
#include <string.h>
 // for strlen(), strcmp(), memcpy() & memset()
#include <stdlib.h>
 // for srand(), rand()
#include <time.h>
 // for time()
#include <sys/socket.h>
 // for socket()
#include <sys/types.h>
 // for stat() and struct stat and pthread types
#include <sys/stat.h>
 // for stat() and struct stat type
#include <pthread.h>
 // for pthread function calls and pthread types
#include <netinet/in.h>
 // for struct in_addr

#include "intuitiveStringOps.h"

bool correctNumberOfArguments(int * pArgC);
bool correctArgs(char * arg);

#endif /* SRC_SPECIFICS_H_ */
