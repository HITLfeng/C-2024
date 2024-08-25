#include <stdlib.h>
#include <string.h>
#include "common.h"

#define READ_STDIN_MAX_LENGTH 128

void SayHello()
{
    printf("hello world\n");
}

Status TestFileOpen()
{
    const char *fileName = "qmys.txt";
    FILE *pf = fopen(fileName, "a");
    if (pf == NULL) {
        error_info("open file failed");
        return ERR_file_opetarion;
    }

    fputs("剑出鞘 恩怨了 谁笑\n", pf);
    fputs("我只求今生 用你入 怀抱\n", pf);


    int ret = fclose(pf);
    if (ret == EOF) {
        error_info("close file failed");
        return ERR_file_opetarion;
    }
    return ERR_OK;
}

void MyScanf()
{
    char *buf = malloc(READ_STDIN_MAX_LENGTH);
    fgets(buf, READ_STDIN_MAX_LENGTH, stdin);

    normal_info("get buf and buf is %s\n", buf);
}

void ProcessOperation()
{
    system("ls");
}

void TestPError()
{
    char *name = "wujiahangsimida";
    char arr[10] = {0};
    memcpy(arr, name, strlen(name));
    perror("error message:");
}
