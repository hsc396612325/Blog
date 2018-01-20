#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define W 7
#define H 7
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];  
	int top;  
}SeqStack; 

//新建一个空栈
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
 
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
SeqStack *SS;

int book[W][H] ={0};//标记
int next[8][2]={{-2,1}, //下一步走法 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
int step=0;	   
int t=0;         
int dfs(Elemtype e){

	 int k,step=1;
	 int i,j;
	 Elemtype e1=e,e2;
	 e1.direction=0;
	 do{
			
		for(k=e1.direction;k<8;k++){
			
			e2.x=e1.x+next[k][0];
			e2.y=e1.y+next[k][1];
			e1.direction = k; 
			
			if(e2.x<0||e2.x>=W||e2.y<0||e2.y>=H)
				continue;
		
			if(book[e2.x][e2.y]==0){
				book[e1.x][e1.y]=step;//标记
				Push(SS,e1);
				//printf("入(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
				e1 = e2;
				e1.direction=0;
				step++;
				break;
			}
		}	
		
		if(step==H*W){//打印 
		
			book[e1.x][e1.y]=step;
			for(i=0;i<H;i++){ 
				for(j=0;j<W;j++)
					printf("%4d",book[i][j]);
			 	printf("\n");
			} 
			t++;
			printf("第%d种走法\n",t);
			book[e1.x][e1.y]=0;
			
		}
		if(k==8||step==H*W){ 
			Pop(SS,&e1);	
			//printf("出(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
		 	book[e1.x][e1.y]=0;
			step--;
			e1.direction++;
		}	
			
	}while(!StackEmpty(SS)||e1.direction!=8); 
		
	return ;	
}

int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;
	e.y=0;
	book[0][0]=step;//标记起始点
	int a=clock();
	dfs(e);
	int b=clock();
	printf("\n%lf秒\n",(b-a)/1000.0);
}
 
	            