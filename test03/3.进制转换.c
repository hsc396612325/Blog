#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30 //栈的最大存储空间
#define TRUE 1
#define FALSE 0 
#define RADIX 2
typedef int Elemtype;
typedef struct
{
    Elemtype data[MAXSIZE];//栈,类型根据情况而定 
    int top;//指向栈顶 
}SeqStack; 

//栈的初始化 
SeqStack *InitStack (){
    //申请空间 
    SeqStack *S;
    S=malloc(sizeof(SeqStack));
    //栈顶初始化 
    S->top =-1; 
    return S;
}


//入栈
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1)//栈已满，添加失败 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//空栈，出栈失败
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 
SeqStack *SS;
void Convert(int num){
	int i;
	while(num){
		i=num%RADIX;
		num=num/RADIX;
		Push(SS,i); 	
	}
} 
int main(void){
	
	int i,num;
	SS=InitStack();
	//printf("请输入要转换的数\n");
	//scanf("%d",&num);
	for(num=0;num<16;num++){
		Convert(num);
		while(SS->top!=-1){
			printf("%d",i,Pop(SS,&i));
		}
		printf("\n");
	}
}