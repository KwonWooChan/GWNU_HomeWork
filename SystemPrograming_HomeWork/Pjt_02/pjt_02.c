/*
 * Project#2 : �ؽ�Ʈ ���ϳ� �ܾ��� ���� ī��Ʈ 
 * �ۼ��� : �ǿ��� 
 * �ۼ��� : 2018.11.05 
 */
 
 #include<stdio.h>
 #include<string.h>
 
 int num, alpha, ect;
	
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
	printf("=========================\n");
	printf("Number of number token = %d\n", num);
	printf("Number of alphabet token = %d\n", alpha);
	printf("Number of ect token = %d\n", ect);
	return 0;
}

int get_token_num(char *bp){
	char *cp;
	int n = 0;
	
	for(cp = strtok(bp," \t\n"); cp != NULL;){
		n++;
		check_char_type(cp);
		cp = strtok(NULL, " \t\n");
	}
	
	return n;
}

void check_char_type(char *ap){
	int x;
	char y = '\'';
	
	x = atoi(ap);
	
	if(ap[1] == y){
	//	printf("%s is ect character \n", ap);
		ect++;
	}else if(x){
	//	printf("%s is num\n", ap);
		num++;
	}else{
	//	printf("%s is English character\n", ap);
		alpha++;
	}
}	
