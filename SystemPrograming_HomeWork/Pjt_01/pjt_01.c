/*
 * Project#1 : �ؽ�Ʈ ���ϳ� �ܾ��� �� ���� ī��Ʈ 
 * �ۼ��� : �ǿ��� 
 * �ۼ��� : 2018.11.05 
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
