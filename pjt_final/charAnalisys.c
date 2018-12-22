# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include <math.h>

extern char Label[10], Opcode[10], Operand[20];

//���� ���ڿ��� int������ �ٲٱ� 
//���ڿ��� ���̸�ŭ 16������ �ٲ۴�. 
int HexToInt(char buf[], int strsize){
	int i, j;

	char* eptr;   //strtol�Լ��� ����ϱ����� �����Դϴ�.
	char tohex[10];   //���ڴܾ �����ϱ����� �迭�Դϴ�.

	int hex = 0;  //�ܾ� �ϳ��� ��Ÿ���� ���� �������ϴ�. 
	int asc = 0;
	int dec = 0;
	
	if(buf[0] == 'X' &&buf[1] == '\'' && buf[strsize-1] == '\''){	//ó���� x�� �����ϸ� �׵ڿ� '�ν����Ͽ� '�� ������ �մϴ�. 
		printf("%s \n", buf);	//������� ���� �ڵ��Դϴ�. 
		for(i = 2; i < strsize-1; i++){	//ó������ '���� �����Ͽ� '�� �ö����� �ݺ��մϴ�. 
			tohex[i-2] = buf[i];   //���ο� �迭�� �����մϴ�.
		}
		
		hex = (int)strtol(tohex, &eptr, 16);    //16���� ��ȯ�մϴ�.
		
		printf("%d \n", hex);	//������� ���� �ڵ��Դϴ�. 
		return hex;
	}else if(buf[0] == 'C' && buf[1] == '\'' && buf[strsize-1] == '\''){
		printf("%s \n", buf);	//������� ���� �ڵ��Դϴ�. 
		for(i = 2; i < strsize-1; i++){
			asc += buf[i];		//�ƽ�Ű�ڵ尪 ��ü�� �����ݴϴ�. 
			printf("%x----%d \n", asc, asc);	//������� ���� �ڵ��Դϴ�.
			asc = asc << 8;	//�ڸ����� �̵���ŵ�ϴ�. 
		}
		asc = asc >> 8;	//�������� ���ʿ��� �ڸ��� �̵��� �����·� ������ŵ�ϴ�. 
		return asc;
	}else{
		dec = atoi(buf);
		return dec;
	}
	return 0;
} 

//number������ 
//6���� ���� ���ڿ��� ����
//ObjectCode�� ���� 
void numto(double number, char * ObjectCode){
	char temp[7] = {0,0,0,0,0,0,'\0'};
	int i , k;
	double tm;
	
	for(i = 5; i >= 0; i--){
		for(k = i, tm = 1; k > 0; k--){
			tm = 16*tm;
		}
		temp[5-i] = (char)(number / tm);
		number = fmod(number,tm);	
		if(temp[5-i] < 10){
			temp[5-i] += 48;	//'0'-'9'
		}else{
			temp[5-i] += 55;	//'A'-'F' 
		}
	}
	
	//strcpy(ObjectCode, tmep); -> temp�� const����� �ƴϹǷ� ������ ���� �ʴ´�. 
	for(i = 0; i < 7; i++){
		ObjectCode[i] = temp[i];
	}
}

//OPCODE�� �ִ� 2����. 
void opcodeto(int symint, char * Symvalue){
	char temp[3] = {0,0,'\0'};
	int i , k;
	int tm;
	
	for(i = 1; i >= 0; i--){
		for(k = i, tm = 1; k > 0; k--){
			tm = 16*tm;
		}
		temp[1-i] = (char)(symint / tm);
		symint = symint%tm;	
		if(temp[1-i] < 10){
			temp[1-i] += 48;	//'0'-'9'
		}else{
			temp[1-i] += 55;	//'A'-'F' 
		}
	}
	
	//���� 
	for(i = 0; i < 3; i++){
		Symvalue[i] = temp[i];
	}
}
//OPERAND�� �ִ� 4�����̹Ƿ� �ۼ����� �� �ִ�. 
void operandto(int symint, char * Symvalue)
{
	char temp[5] = {0,0,0,0,'\0'};
	int i , k;
	int tm;
	for(i = 3; i >= 0; i--)
	{
		for(k = i, tm = 1; k > 0; k--)
		{
			tm = 16*tm;
		}
		temp[3-i] = (char)(symint / tm);
		symint = symint%tm;	
		if(temp[3-i] < 10){
			temp[3-i] += 48;	//'0'-'9'
		}else{
			temp[3-i] += 55;	//'A'-'F' 
		}
	}

	// �����ڵ忡 x�κп� ���� �ִ´�. 
	if(strchr(Operand,',')!=NULL){
		temp[0] += 8;
	}
	//���� 
	for(i = 0; i < 5; i++){
		Symvalue[i] = temp[i];
	}
}
