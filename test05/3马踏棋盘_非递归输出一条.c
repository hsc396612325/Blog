#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define H 7
#define W 7 
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//栈,类型根据情况而定 
	int top;//指向栈顶 
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
int dfs(Elemtype e){

	 int k,step=1;
	 Elemtype e1=e,e2;//e1：待入栈元素。e2：e1试探方向的元素 
	 e1.direction=0;
	 
	while(step!=W*H){
			
		for(k=e1.direction;k<8;k++){ //如果上一步是入栈，则e1.direction=0，如果上一步是出栈则e1.direction++ 
			
			e2.x=e1.x+next[k][0];
			e2.y=e1.y+next[k][1];
			e1.direction = k;//e1到e2的走法 
			
			if(e2.x<0||e2.x>H||e2.y<0||e2.y>=W)
				continue;
		
			if(book[e2.x][e2.y]==0){
				book[e1.x][e1.y]=step;
				Push(SS,e1);//入栈e1 
				
				e1 = e2; //原e2变成e1(待入栈) 
				e1.direction=0;//下次试探从0开始 
				step++;
				break;
			}
		}
		if(k==8){
			Pop(SS,&e1);//出栈栈顶元素，栈顶元素称为新的e1(待入栈) 
			
		 	book[e1.x][e1.y]=0; 
			step--;
			e1.direction++;//下次试探接着入栈键的方向 
		}			
	}
	
	//标记终点元素 
	book[e1.x][e1.y]=step;
	
	int i,j;
	if(step==W*H){//打印 
		for(i=0;i<H;i++){ 
			for(j=0;j<W;j++)
				printf("%4d",book[i][j]);
		 	printf("\n");
		} 	
	}
	return ;	
}

int main(void)
{
	Elemtype e;
	
	SS=InitStack();
	printf("请输入起点坐标：\n");
	scanf("%d%d",&e.x,&e.y);
	book[e.x][e.y]=step;//标记起始点
	
	int a=clock();
	dfs(e);
	int b=clock();
	printf("\n%lf秒\n",(b-a)/1000.0);
}
 
	            