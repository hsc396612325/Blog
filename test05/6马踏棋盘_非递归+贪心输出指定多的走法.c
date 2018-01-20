#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define W 8
#define H 8
#define Q 3 //每个方向只遍历权值排前三的方法 
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

typedef struct{ 
	int value;
	int direction;
}Value;
//新建一个空栈
SeqStack *InitStack (){
	//申请空间 
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
int step=1;   
int count, t=0;      
void Sortint(Elemtype e , Value b[8]){ //计算e点8个方向的权值，并排序 
	Elemtype e1,e2;
	int k1,k2;
	for(k1=0;k1<8;k1++){
		e1.x = e.x+next[k1][0];
		e1.y = e.y+next[k1][1];
		
		b[k1].direction=k1;
		b[k1].value=0;
		if(book[e1.x][e1.y]!=0||e1.x<0||e1.y<0||e1.x>=H||e1.y>=W)//如果这个点不能走，则跳过这个点
			continue;
		
		for(k2=0;k2<8;k2++){//计算这个点的权值 
			e2.x= e1.x+next[k2][0];
			e2.y= e1.y+next[k2][1];
			if(book[e2.x][e2.y]!=0|| e2.x<0 ||e2.y<0 ||e2.x>=H ||e2.y>=W )
				continue;
			
			 b[k1].value++;//权值加一 
		} 
	}
	//按权值大小排序(插入排序，0放末尾) 
	int i,j;
	Value t;
	for(i=1;i<8;i++){
		t=b[i];
		for(j=i-1;j!=-1&&(t.value<b[j].value||b[j].value==0)&&t.value!=0;j--)
			b[j+1]=b[j];
		b[j+1]=t;
	
	}
	return ;
}
  
int dfs(Elemtype e){

	int k;
	Value b[8];//存放8个方向权值 
	Elemtype e1=e,e2;//e1当前待入栈点，e2：e1试探方向的元素 
	int i,j;
	
	Sortint(e1,b);//计算权值 
	e1.direction=0;
	do{
	
		Sortint(e1,b);//计算权值 
		k=e1.direction;
				
		if(b[k].value!=0&&k<Q){   //只遍历权值排名前Q的方向 
			e1.direction = k;//k为当前权值的下标 
			
			//入栈 
			Push(SS,e1); 
			book[e1.x][e1.y]=step;
			step++;
			 //printf("入(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
			//更新e1 
			e1.x = e1.x+next[b[k].direction][0];
			e1.y = e1.y+next[b[k].direction][1];
			e1.direction=0; 
		}
		
		if(step==W*H){  
			t++; 
			book[e1.x][e1.y]=step;	
	     	 //打印 
			for(i=0;i<H;i++){ 
				for(j=0;j<W;j++)
					printf("%4d",book[i][j]);
		 		printf("\n");
			} 
			printf("第%d种走法\n\n",t); 
			book[e1.x][e1.y]=0;	 
		}
		if(b[k].value==0||step==W*H||k>=Q){
			//出栈 并更新e1 
			Pop(SS,&e1);
			//printf("出(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top); 
			book[e1.x][e1.y]=0; 
			step--;
			e1.direction++;//下次试探接着入栈键的方向 
		}
	}while(count!= t);  
}

int main(void)
{
	Elemtype e;
	SS=InitStack();
	printf("请输入起点坐标：\n");
	scanf("%d%d",&e.x,&e.y);
	book[e.x][e.y]=step;//标记起始点
	printf("要计算多少种走法:\n");
	scanf("%d",&count);
	int a=clock();
	dfs(e);
	int b=clock();
	printf("\n%lf秒\n",(b-a)/1000.0);
	getchar();
}
 
	            