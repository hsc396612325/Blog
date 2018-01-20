#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30 //栈的最大存储空间
#define TRUE 1
#define FALSE 0 
typedef char Elemtype;
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
int f1(char string[]){
	SeqStack *seq; 
	seq=InitStack();
	int i;
	char c;
	for(i=0;i<strlen(string)/2;i++){
		Push(seq,string[i]);
	}
	
	for(i=i+strlen(string)%2;string[i];i++){
		Pop(seq,&c);
		if(c!=string[i]){
			printf("不是回文\n");
				break;
		}		
	}
	
	if(i==strlen(string))
		printf("是回文\n");
} 
int main(void){
	char string[30];
	printf("请输入字符串：");
	gets(string);	
	
	f1(string);
} 