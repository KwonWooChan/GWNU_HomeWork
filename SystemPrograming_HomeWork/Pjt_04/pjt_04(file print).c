/*
 * Project#3 : 텍스트 파일내 단어의 총 합을 카운트 
 * 작성자 : 권우찬 
 * 작성일 : 2018.11.06
 */
 
 #include<stdio.h>
 #include<string.h>
 
int get_token_num(char *bp, FILE * fp);
void mk_lines(char *ap, FILE * fp);
 
long Line;

	
int main(){
 	FILE *fp1, *fp2;
	char buf[80];
	int n = 0;
	
	
	if((fp1=fopen("./sample.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	if((fp2=fopen("./sample_lines.s", "w")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp1) != NULL){
		n += get_token_num(buf, fp2);
	}
	
	fprintf(fp2, "================\n");
	fprintf(fp2, "Number of token = %d\n", n);
	
	fclose(fp1);
	fclose(fp2);
		
	return 0;
}

int get_token_num(char *bp, FILE *fp){
	char *cp;
	int n = 0;
	
	for(cp = strtok(bp," \t\n"); cp != NULL;){
		n++;
		mk_lines(cp, fp);
		cp = strtok(NULL, " \t\n");
	}
	
	fprintf(fp, "%02X\n", Line);
	
	return n;
}

void mk_lines(char *ap, FILE *fp){
	int i = 0;
	int length = 0;
	
	
	while(1){
		if(ap[i] == ' ' || ap[i] == '\t' || ap[i] == '\n' || ap[i] == '\0'){
			break;
		}
		
		i++;
	}
	length = i;
	
	fprintf(fp, "%02X : %s\n", Line, ap);
	
	Line += length;
}

