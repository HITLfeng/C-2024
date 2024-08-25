#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>


//调试打印开关
#define __DEBUG
 
#ifdef __DEBUG
#define normal_info(format, ...) printf("["__FILE__"][Line: %d][%s]: \033[32m"format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#define warning_info(format, ...) printf("["__FILE__"][Line: %d][%s]: \033[33m"format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#define error_info(format, ...) printf("["__FILE__"][Line: %d][%s]: \033[31m"format"\033[32;0m\n", __LINE__, __func__, ##__VA_ARGS__)
#else
#define normal_info(format, ...)
#define warn_info(format, ...)
#define error_info(format, ...)
#endif

typedef int int32_t;
typedef int32_t Status;
// error no
#define ERR_OK 0
#define ERR_file_opetarion -1
#define true 1
#define false 0




void SayHello();

Status TestFileOpen();

void MyScanf();

void ProcessOperation();

void TestPError();

void TestPipe();
void TestShmem();


#endif // __COMMON_H__

