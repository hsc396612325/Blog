#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define H 8
#define W 8
int book[H][W] ={0};//标记
int t=0;          
void dfs(int x,int y,int step){
	int next[8][2]={{-2,1}, //下一步走法 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
    int i,j;
    
	if(step==W*H){//打印 
		for(i=0;i<H;i++){ 
		
			for(j=0;j<W;j++)
					printf("%4d",book[i][j]);
			 	printf("\n");
			} 
			t++;
			printf("%d\n",t);
			return ;
	}	
	
	int k,tx,ty;
	for(k=0;k<8;k++){
		tx = x+next[k][0];
		ty = y+next[k][1]; 
		
		if(tx<0||ty<0||tx>=H||ty>=W){
			continue;
		}
		if(book[tx][ty]==0){
			book[tx][ty]=step+1;
			//printf("入(%d %d) %d\n",tx,ty,step+1);
			dfs(tx,ty,step+1);
			//printf("出(%d %d)\n",tx,ty);
			
			book[tx][ty]=0;
		}
	}
	return;
}
int main(void)
{

	book[0][0]=1;//标记起始点
	
	int a=clock();
	dfs(0,0,1);//第一个参数是起始点的x坐标，第二个参数是起始点的y坐标，第三个参数是步数 
	int b=clock();
	printf("\n%lf秒\n",(b-a)/1000.0);
}
 
	            