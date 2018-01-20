#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40
#define TRUE 1
#define FALSE 0 
typedef struct
{
	char string[10]; 
} Elemtype;
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
int Priority(Elemtype e1){
	switch(e1.string[0]){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '(':
			return 0;
		case ')':
			return 0;
	}
}
SeqStack *sign;//符号 
Elemtype result[50];//结果
int result_top=0;
int Convert(char str[]) {
	Elemtype e1,e2,e3; //e1,表达式截取的数字。e2,表达式截取的符号(待入栈)。e3符号栈栈顶符号 
	int i,j,count=0; //count计算数字的长度 
	
	for(i=0;str[i];i++){
		if(str[i]>='0'&&str[i]<='9'){ //如果是数字
			e1.string[count]=str[i];
			count++; 
		}  
		else{
			if(count>0){ 
				e1.string[count]=0;
				result[result_top]=e1;//数字存入结果数组中 
				result_top++; 
			}
			
			e2.string[0]=str[i];
			e2.string[1]=0;
			
			if(str[i]=='('){      //左括号直接入栈 
				Push(sign,e2); 
			}else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'){ 				
				
				GetTop(sign,&e3);
				//和栈顶元素比较，如果比栈顶元素优先级低/相等，出栈栈顶
				//直到栈空，或着当前符号比栈顶元素优先级高，或者碰到'(' 
				while(StackEmpty(sign)==0&&Priority(e2)<=Priority(e3)&&e3.string[0]!='('){  
					Pop(sign,&e3);//出栈 
					result[result_top]=e3;//存入结果数组中 
					result_top++; 
					GetTop(sign,&e3);//取出下一个栈顶元素 
				}
				if(e2.string[0]!=')'){//如果当前符号不是')',将符号入栈 
					Push(sign,e2);	
				}else{            //如果是')',出栈栈顶的'('符号 
					Pop(sign,&e3);
				}	
			}else {
				printf("错误!");
				return;
			} 
		 	count=0;//数字的计数器重置 
		}
	}
	//结束时
	e1.string[count]=0;
	result[result_top]=e1;//存入结果数组中 
	result_top++;  
	while(!StackEmpty(sign)){
		Pop(sign,&e3);
		result[result_top]=e3;//存入结果数组中 
		result_top++;  
	}
	
	for(i=0;i<result_top;i++){
		printf("%s ",result[i].string);
	}
	printf("\n");
}
int main(void){
	sign=InitStack(); 
	char str[100]="9+(3-1)*3+10/2";
	//scanf("%s",str); 
	Convert(str);
}