#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"path1.h"
#include"path2.h"
//2pass ������ ����� 
int main()
{
	printf("***ASSEMBLER START!!!***\n");
	
	path1();	
	path2();
	
	printf("***ASSEMBLER END!!!***");
	
	return 0;
}
