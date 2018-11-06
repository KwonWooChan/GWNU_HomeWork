/*
 * Project#1 : 텍스트 파일내 단어의 총 수를 카운트 
 * 작성자 : 권우찬 
 * 작성일 : 2018.11.05 
 */
 
 #include<stdio.h>
 #include<string.h>
 
 int main(){
 	FILE *fp;
	char buf[80];
	int n = 0;
	
	if((fp=fopen("./smple.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		n += get_token_num(buf);
	}
	
	fclose(fp);
	printf("Number of token = %d\n", n);
	
	return 0;
}

int get_token_num(char *bp){
	char *cp;
	int n = 0;
	
	for(cp = strtok(bp," \t\n"); cp != NULL;){
		n++;
		cp = strtok(NULL, " \t\n");
	}
	
	return n;
}
