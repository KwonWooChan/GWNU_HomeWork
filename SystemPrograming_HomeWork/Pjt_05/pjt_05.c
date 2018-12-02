/*
 * Project#5 : 예약된 단어들을 기본으로 줄 길이 구하는 프로그램 
 * 작성자 : 권우찬 
 * 작성일 : 2018.12.02
 */
 
 
 //pjt_01.c를 활용했습니다. 
 #include<stdio.h>
 #include<string.h>
void mk_lines(char* );
void mk_size(char*); 

typedef struct OPTAB{
	char name[8];
	int len;
} OPTAB;

OPTAB Wordtab[] = {{"LDA", 3}, {"STA", 4}, {"TIX", 2}, {"ADD", 3}, {"JP", 4}};
int Size;
int Line;
	
int main(){
 	FILE *fp;
	char buf[80];
	int n = 0;
	
	Size = 0;
	Line = 0;
	
	/*파일 입력*/ 
	if((fp=fopen("./words.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		n += get_token_num(buf);
		/*단어확인*/ 
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
		mk_size(cp);
		cp = strtok(NULL, " \t\n");
	}
	
	//마지막에 총 라인수를 적어주기 위해서 for문 밖에 선언을 해주었다.
	//이 부분은 for문 이후에 진행이 되는 곳이라면 어디든지 선언되어도 좋다. 
	//printf("%02X\n", Line);
	
	return n;
}
//공백문자열이 있다면 그 부분까지만 읽어서 단어의 숫자를 세는 함수입니다.
//줄의 번호를 붙여주는 함수이기 때문에 mk_lines라고 선언해주었지만
//조금 다른의미로 사용하고 있는 함수인거 같습니다. 
void mk_lines(char *ap){
	Line++;
	printf("%d, %02x, %s, ", Line, Size, ap);
}
void mk_size(char *ap){
	int i = 0, j=0;
	int length = 0;
	
	
	while(1){
		//마지막 men을 확인해줄때 오류가 나서 확인해준 결과
		//null 값을 무시했기 때문에 발생한것을 확인했다. 
		if(ap[i] == ' ' || ap[i] == '\t' || ap[i] == '\n' || ap[i] == '\0'){
			ap[i] = '\0';
			break;
		}
		
		i++;
	}
	for(j =0; j<sizeof(Wordtab)/sizeof(OPTAB) ; j++){
		if(strcmp(Wordtab[j].name, ap) == 0){
			length = Wordtab[j].len;
		}
	}
	if(length == 0){
		printf("Undefined wowrd\n");
		return;
	}
	
	printf("%02X\n", length);
	
	Size += length;
}

