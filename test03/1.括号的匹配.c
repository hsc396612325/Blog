#include <stdio.h>
#include <stdlib.h>
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
void f1(char string[]){
	
	SeqStack *seq; 
	char c;
	int i;
	seq=InitStack();
	for(i=0;string[i];i++)
	{
		
		if(string[i]=='('||string[i]=='{'||string[i]=='['){
			Push(seq,string[i]);	//入栈	
		}else{
			
			if(seq->top==-1){//判断是否栈空
				printf("不配对!\n");
				return; //结束匹配 
			}else{
				Pop(seq,&c);//出栈 
				switch(string[i]){
					case ')' : 
						if(c!='('){
							printf("不匹配\n");
							return;
						}
						break;
					case ']' :
						if(c!='['){
							printf("不匹配\n");
							return;
						}
						break;
					case '}' :
						if(c!='{'){
							printf("不匹配\n");
							return;
						}
						break;
					default :
						printf("不匹配\n");
						return;
				}	
			}
		}		
	}
	
	
	if(seq->top!=-1){
		printf("不配对!\n");
		return;
	}
	
	printf("配对成功\n");

 }
int main(){
	char string[20];
	int i; 
	printf("请输入括号串：");
	gets(string);	
	f1(string);
}