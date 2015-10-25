/*
 * testmain.h
 *
 *  Created on: Oct 24, 2015
 *      Author: dcipher
 */

#ifndef SRC_TESTMAIN_H_
#define SRC_TESTMAIN_H_

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
#include "specifics.h"

void typesizereference();
int tests(int argc, char * argv[]);

#endif /* SRC_TESTMAIN_H_ */
