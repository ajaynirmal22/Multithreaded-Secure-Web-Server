#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>    
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>	
#include "error_codes.h"

#define PATH "./static" 
int PORT_NO = 8080;
#define BUFFER_SIZE 1024
#define CONNECTION_NUMBER 10
