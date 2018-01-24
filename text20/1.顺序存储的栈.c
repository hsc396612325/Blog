#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0 
typedef int Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE]; 
	int top; 
}SeqStack; 

//新建一个空栈
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=malloc(sizeof(SeqStack));
	 
	S->top =-1; 
	return S;
}


//判断是否为空栈 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//入栈
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1) 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈并返回 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//取出栈顶元素 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 


//返回回栈S的元素个数。
int StackLength (SeqStack *S){
	return S->top +1;
} 

int main(void){
	SeqStack *S;
	int x,y,z;
	S=InitStack();//创建栈
	printf("%d ",S->top);
	printf("%d %d\n",StackEmpty(S),S->top);//判断是否为空
	printf("%d %d %d\n",Push(S,1),Push(S,2),S->top);//入栈并判断是否成功
	printf("%d %d %d\n",Pop(S,&x),Pop(S,&y),Pop(S,&z));//出栈并判断是否成功,z=1,y=2,x=随机数 
	printf("%d %d %d\n",x,y,z); 
	Push(S,3);
	GetTop(S,&z);
	printf("%d %d\n",z,StackLength(S));
	 
}