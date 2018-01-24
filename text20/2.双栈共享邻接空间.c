#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0 
typedef int Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//栈,类型根据情况而定 
	int lefttop;//指向左栈栈顶位置 
	int righttop;//指向右栈站顶位置	 
}DupsqStack; 

//初始化
DupsqStack *InitDupStack(){
	DupsqStack	*S;
	S=(DupsqStack*)malloc(sizeof(DupsqStack*));
	S->lefttop=-1;
	S->righttop=MAXSIZE;
	return S;
}

//入栈
int PushDupStack(DupsqStack *S ,char status ,Elemtype x){
	if(S->lefttop+1 == S->righttop) 
		return FALSE;//栈满
		
	if(status == 'L') 
		S->data[++S->lefttop] =x;
	else if(status == 'R') 
		S->data[--S->righttop] =x;
	else 
		return FALSE;
	return TRUE;	
} 

//出栈
int PopDupStack(DupsqStack *s ,char status,Elemtype *x){
	if(status =='L')
	{
		if(s->lefttop==-1)//空栈 
			return FALSE;
			
		*x=s->data[s->lefttop--];	
		return TRUE;
	}
	else if(status == 'R')
	{
		if(s->righttop==MAXSIZE)//空栈 
			return FALSE;
			
		*x=(s->data[s->righttop++]);
		return TRUE;
	}
	else
		return FALSE;//标志符有错 
}  
int main(void){
	DupsqStack *S;
	S=InitDupStack();
	printf("%d %d\n",S->lefttop,S->righttop);
	PushDupStack(S,'L',4); 
	PushDupStack(S,'R',5); 
	int X;
	printf("%d %d\n",PopDupStack(S,'L',&X),PopDupStack(S,'R',&X));
} 