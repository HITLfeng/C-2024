# <目标文件>:<依赖>
# \t<cmd>

test2: test1.o common.o
	gcc test1.o common.o -o test2

test1.o: test1.c include/common.h
	gcc -c test1.c -o test1.o

common.o: lic/common.c include/common.h
	gcc -c common.c -o common.o