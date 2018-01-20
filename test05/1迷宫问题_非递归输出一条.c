#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
#define W 4 //迷宫的高和宽 
#define H 5 
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
int book[H][W];
int n=3,m=3;//终点坐标 
int a[H][W]={{0,0,1,0}, //地图 
			 {0,0,0,0},
             {0,0,1,1},
			 {0,1,0,0},
			 {0,0,0,0}};

int dfs(Elemtype e){
	int k;
	int next[4][2]={{0,1},//右 
	                {1,0},//下 
			        {0,-1},//左 
	                {-1,0}};//上
	Elemtype e1,e2;    //e1：待入栈，e2：e1的试探方向的坐标 
	e1 = e;
	e1.direction=0;
	while(e1.x!=n||e1.y!=m){ // m n终点坐标 
			
		for(k=e1.direction;k<4;k++){
			
			e2.x=e1.x+next[k][0];//下一步 
			e2.y=e1.y+next[k][1];
			e1.direction=k;
			if(e2.x<0||e2.y<0||e2.y>=W||e2.x>=H)//判断是否越界 
				continue;
				
			if(a[e2.x][e2.y]!=1&&book[e2.x][e2.y]==0)//判断下一步是否被走过和是否有障碍物
			{
				Push(SS,e1);
				book[e1.x][e1.y]=1;//标记
				e1=e2; 
				e1.direction=0;
				//printf("入(%d,%d)%d\n",e1.x,e1.y,e1.direction);
				break;				
			} 
		}
		
		if(k==4){
			Pop(SS,&e1); 
			book[e1.x][e1.y]=0;
			//printf("出(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.direction++;
		}
	}
	
	Push(SS,e1);
	book[e1.x][e1.y]=1;
	
	int i;
	if(e1.x==n&&e1.y==m){
		for(i=0;i<SS->top+1;i++){
			printf("过程(%d,%d)方向:%d\n",SS->data[i].x,SS->data[i].y,SS->data[i].direction); 
		}
	}
}
int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;
	e.y=0;
	e.direction=0;
	book[0][0]=1;//标记起始点
	dfs(e);//第一个参数是起始点的x坐标，第二个参数是起始点的y坐标，第三个参数是步数 
}


