# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include <math.h>

extern char Label[10], Opcode[10], Operand[20];

//숫자 문자열을 int형으로 바꾸기 
//문자열의 길이많큼 16진수로 바꾼다. 
int HexToInt(char buf[], int strsize){
	int i, j;

	char* eptr;   //strtol함수를 사용하기위한 변수입니다.
	char tohex[10];   //숫자단어를 저장하기위한 배열입니다.

	int hex = 0;  //단어 하나당 나타내는 수를 저장힙니다. 
	int asc = 0;
	int dec = 0;
	
	if(buf[0] == 'X' &&buf[1] == '\'' && buf[strsize-1] == '\''){	//처음에 x로 시작하며 그뒤에 '로시작하여 '로 끝나야 합니다. 
		printf("%s \n", buf);	//디버깅을 위한 코드입니다. 
		for(i = 2; i < strsize-1; i++){	//처음오는 '부터 시작하여 '가 올때까지 반복합니다. 
			tohex[i-2] = buf[i];   //새로운 배열에 저장합니다.
		}
		
		hex = (int)strtol(tohex, &eptr, 16);    //16진수 변환합니다.
		
		printf("%d \n", hex);	//디버깅을 위한 코드입니다. 
		return hex;
	}else if(buf[0] == 'C' && buf[1] == '\'' && buf[strsize-1] == '\''){
		printf("%s \n", buf);	//디버깅을 위한 코드입니다. 
		for(i = 2; i < strsize-1; i++){
			asc += buf[i];		//아스키코드값 자체로 더해줍니다. 
			printf("%x----%d \n", asc, asc);	//디버깅을 위한 코드입니다.
			asc = asc << 8;	//자릿수를 이동시킵니다. 
		}
		asc = asc >> 8;	//마지막에 불필요한 자릿수 이동을 원상태로 복구시킵니다. 
		return asc;
	}else{
		dec = atoi(buf);
		return dec;
	}
	return 0;
} 

//number변수를 
//6자의 숫자 문자열을 만들어서
//ObjectCode에 저장 
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
	
	//strcpy(ObjectCode, tmep); -> temp는 const상수가 아니므로 설정이 되지 않는다. 
	for(i = 0; i < 7; i++){
		ObjectCode[i] = temp[i];
	}
}

//OPCODE는 최대 2문자. 
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
	
	//저장 
	for(i = 0; i < 3; i++){
		Symvalue[i] = temp[i];
	}
}
//OPERAND는 최대 4문자이므로 작성해줄 수 있다. 
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

	// 목적코드에 x부분에 값을 넣는다. 
	if(strchr(Operand,',')!=NULL){
		temp[0] += 8;
	}
	//복사 
	for(i = 0; i < 5; i++){
		Symvalue[i] = temp[i];
	}
}
