#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
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
	//申请空间 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	//栈顶初始化 
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
	if(S->top==MAXSIZE-1)//栈已满，添加失败 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//出栈并返回 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//空栈，出栈失败
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//取出栈顶元素 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//空栈，出栈失败
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;
int n,m,p=4,q=3,min=9999999,book[10][10];
int a[5][4]={{0,0,1,0},
             {0,0,0,0},
             {0,0,1,1},
			 {0,1,0,0},
			 {0,0,0,1}};
			   
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},//右 
	                {1,0},//下 
			        {0,-1},//左 
	                {-1,0}};//上
					
	if(x==3&&y==3)
	{
		int i;
		printf("到达\n"); 
		if(step<min)//如果步数比当前最小值小，更新
			min=step;
		for(i=0;i<SS->top+1;i++){
			printf("过程(%d,%d)%d\n",SS->data[i].x,SS->data[i].y,SS->data[i].direction); 
		}
		return;//返回上一步 
	} 
	int tx,ty,k;
	for(k=0;k<4;k++)//枚举所有走法 
	{
		tx=x+next[k][0];//下一步 
		ty=y+next[k][1];
		
		if(tx<0||ty<0||ty>=4||tx>=5)//判断是否越界 
			continue;
			
		if(a[tx][ty]!=1&&book[tx][ty]==0)//判断下一步是否被走过和是否有障碍物
		{
			Elemtype e;
			e.x=tx;
			e.y=ty;
			e.direction=k;
			book[tx][ty]=1;//标记
			Push(SS,e);
			//printf("入(%d,%d)%d %d\n",e.x,e.y,e.direction,step);
			dfs(tx,ty,step+1);//走下一个节点
			book[tx][ty]=0;//当该节点退出(回溯)时，取消标记
			//printf("出(%d,%d)%d\n",e.x,e.y,e.direction); 
			Pop(SS,&e);
		} 
	}
	return;
	 
}
int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;
	e.y=0;
	e.direction=0;
	Push(SS,e);
	book[0][0]=1;//标记起始点
	dfs(0,0,0);//第一个参数是起始点的x坐标，第二个参数是起始点的y坐标，第三个参数是步数 
	printf("%d\n",min);
}


