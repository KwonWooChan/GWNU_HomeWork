/*
 * Project#5 : ����� �ܾ���� �⺻���� �� ���� ���ϴ� ���α׷� 
 * �ۼ��� : �ǿ��� 
 * �ۼ��� : 2018.12.02
 */
 
 
 //pjt_01.c�� Ȱ���߽��ϴ�. 
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
	
	/*���� �Է�*/ 
	if((fp=fopen("./words.s", "r")) == NULL){
		fprintf(stderr, "file not found...\n");
		return 1;
	}
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		n += get_token_num(buf);
		/*�ܾ�Ȯ��*/ 
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
	
	//�������� �� ���μ��� �����ֱ� ���ؼ� for�� �ۿ� ������ ���־���.
	//�� �κ��� for�� ���Ŀ� ������ �Ǵ� ���̶�� ������ ����Ǿ ����. 
	//printf("%02X\n", Line);
	
	return n;
}
//���鹮�ڿ��� �ִٸ� �� �κб����� �о �ܾ��� ���ڸ� ���� �Լ��Դϴ�.
//���� ��ȣ�� �ٿ��ִ� �Լ��̱� ������ mk_lines��� �������־�����
//���� �ٸ��ǹ̷� ����ϰ� �ִ� �Լ��ΰ� �����ϴ�. 
void mk_lines(char *ap){
	Line++;
	printf("%d, %02x, %s, ", Line, Size, ap);
}
void mk_size(char *ap){
	int i = 0, j=0;
	int length = 0;
	
	
	while(1){
		//������ men�� Ȯ�����ٶ� ������ ���� Ȯ������ ���
		//null ���� �����߱� ������ �߻��Ѱ��� Ȯ���ߴ�. 
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

