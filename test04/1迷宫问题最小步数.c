#include <stdio.h>
#include <string.h>
#define H 5
#define W 4 
#define Accept_x 3
#define Accept_y 3
int min=999999,book[10][10];
int a[H][W]={{0,0,1,0},
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
					
	if(x==Accept_x&&y==Accept_y)
	{
		printf("到达 %d\n",step); 
		if(step<min)//如果步数比当前最小值小，更新
			min=step;
			
		return;//返回上一步 
	} 
	int tx,ty,k;
	for(k=0;k<4;k++)//枚举所有走法 
	{
		tx=x+next[k][0];//下一步 
		ty=y+next[k][1];
		
		if(tx<0||ty<0||ty>=W||tx>=H)//判断是否越界 
			continue;
			
		if(a[tx][ty]!=1&&book[tx][ty]==0)//判断下一步是否被走过和是否有障碍物
		{
			book[tx][ty]=1;//标记
			//printf("入(%d,%d)%d %d\n",tx,ty,k,step);
			dfs(tx,ty,step+1);//走下一个节点
			book[tx][ty]=0;//当该节点退出(回溯)时，取消标记
			//printf("出(%d,%d)%d %d\n",tx,ty,k,step); 
		} 
	}
	return;
	 
}
int main(void)
{
	book[0][0]=1;//标记起始点
	dfs(0,0,0);//第一个参数是起始点的x坐标，第二个参数是起始点的y坐标，第三个参数是步数 
	printf("%d\n",min);
}