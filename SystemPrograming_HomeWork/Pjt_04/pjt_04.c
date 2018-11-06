/*
 * Project#3 : 텍스트 파일내 단어의 총 합을 카운트 
 * 작성자 : 권우찬 
 * 작성일 : 2018.11.06
 */
 
 #include<stdio.h>
 #include<string.h>
 
int get_token_num(char *bp);
void mk_lines(char *ap);
 
long Line;

	
int main(){
 	FILE *fp;
	char buf[80];
	int n = 0;
	
	
	if((fp=fopen("./sample.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		n += get_token_num(buf);
	}
	
	fclose(fp);
	
	printf("================\n");
	printf("Number of token = %d\n", n);
	
	return 0;
}

int get_token_num(char *bp){
	char *cp;
	int n = 0;
	
	for(cp = strtok(bp," \t\n"); cp != NULL;){
		n++;
		mk_lines(cp);
		cp = strtok(NULL, " \t\n");
	}
	
	printf("%02X\n", Line);
	
	return n;
}

void mk_lines(char *ap){
	int i = 0;
	int length = 0;
	
	
	while(1){
		if(ap[i] == ' ' || ap[i] == '\t' || ap[i] == '\n' || ap[i] == '\0'){
			break;
		}
		
		i++;
	}
	length = i;
	
	printf("%02X : %s\n", Line, ap);
	
	Line += length;
}

