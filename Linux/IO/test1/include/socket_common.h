#ifndef __SOCKET_COMMON_H__
#define __SOCKET_COMMON_H__

#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR_SOCKET 1001001
#define ERR_BIND 1001002
#define ERR_LISTEN 1001003
#define ERR_ACCEPT 1001004

#define ERR_SOCKET_CLIENT 1002001
#define ERR_BIND_CLIENT 1002002
#define ERR_CONNECT_CLIENT 1002003

Status ClientMain();

#endif // __SOCKET_COMMON_H__