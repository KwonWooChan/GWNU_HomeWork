/*
 * Project#3 : 텍스트 파일내 단어의 총 합을 카운트 
 * 작성자 : 권우찬 
 * 작성일 : 2018.11.06
 */
 
 #include<stdio.h>
 #include<string.h>
 
int get_token_num(char *bp);
void check_numb(char *ap);
 
long Total;

	
int main(){
 	FILE *fp;
	char buf[80];
	int n = 0;
	
	
	if((fp=fopen("./numb.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		n += get_token_num(buf);
	}
	
	fclose(fp);
	printf("Number of token = %d\n", n);
	printf("The Total = %0#X\n", Total);
	
	return 0;
}

int get_token_num(char *bp){
	char *cp;
	int n = 0;
	
	for(cp = strtok(bp," \t\n"); cp != NULL;){
		n++;
		check_numb(cp);
		cp = strtok(NULL, " \t\n");
	}
	
	return n;
}

void check_numb(char *ap){
	unsigned long numb = 0;
	int i;
	
	if(ap[0] == 'x' || ap[0] == 'X'){
		for(i = 2; 1; i++){
			if(ap[i] == '\''){
				break;
			}
			
			numb = numb << 4;
			
			switch(ap[i]){
			case '0':	case '1':	case '2':	case '3':	case '4':
			case '5':	case '6':	case '7':	case '8':	case '9':
				numb = numb | (ap[i] - '0');
				break;
			case 'A':	case 'B':	case 'C':	case 'D':	case 'E':	case 'F':
				numb = numb | (ap[i] - 'A' + 10);
				break;
			default:
				break;
			}
		}
	}else if(ap[0] == 'c' || ap[0] == 'C'){
		for(i = 2; 1; i++){
			if(ap[i] == '\''){
				break;
			}
			numb = numb << 8;
			numb = numb | ap[i];
		}
	}else{
		numb = atoi(ap);
	}
	
	Total = Total + numb;
}
