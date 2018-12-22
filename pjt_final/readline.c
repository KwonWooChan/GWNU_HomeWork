# include <stdio.h>
# include <stdlib.h>
# include <string.h>
extern char Label[10], Opcode[10], Operand[10];

int readline(FILE* fp) 
{
	int i , j, k;
	int linenumb;
	//	linenumb	 :	 label	 :	Opcode	:	Operand	:	NULL
	//	col[0]		:	col[1]	:	col[2]	:	col[3]	:	col[4]
	char * col[5];
	char * ep = "";
	char str[50];
	
	//최대 50글자의 한줄을 읽는다.
	//공백을 기준으로 나누고 각 부분에 따라서 다르게 저장을 해준다. 
	if(fgets(str, 50, fp) != NULL){
		if(str[0] != '\n'){
			for(i = 1, col[0] = strtok(str," \t\n"); col[i-1] != NULL; i++){
				col[i] = strtok(NULL," \t\n");
			}
			
			linenumb = strtol(col[0],&ep, 10);
			if(i == 5){
				strcpy(Label,col[1]);
				strcpy(Opcode,col[2]);
				strcpy(Operand,col[3]);
			}else if(i == 4){
				strcpy(Label, "\t");
				strcpy(Opcode, col[1]);
				strcpy(Operand, col[2]);
			}else if(i == 3){
				strcpy(Label, "\t");
				strcpy(Opcode, col[1]);
				strcpy(Operand, "\t");
			}
		}else{
			i = 1;
		}
	}	
	
	printf("%-4d readline %s %s %s\n", linenumb, Label, Opcode, Operand);
	
	return i-1;
}
