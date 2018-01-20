
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

#define WIDTH 700
#define HEIGHT 900
int score,score_i;
//int map[4][4]={{2048,1024,512,256},{16,32,64,128},{8,4,2}};
int map[4][4]={0};

void show1()
{
	cleardevice();//清屏

	setfont(70,0,"方正行黑简体");//字体设置
	RECT r1={0,0,WIDTH,HEIGHT/3};
	drawtext("欢迎来到2048的世界",&r1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	setfont(30,0,"微软雅黑");
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("开始游戏",&r2,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
	drawtext("游戏介绍",&r3,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("操作说明",&r4,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("退出游戏",&r5,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	setfillcolor(RGB(244,186,1));//设置当前的填充颜色
	solidroundrect(216,478,484,746,50,50);
	setfont(145,0,"Microsoft Yahei UI Bold");//设置字体
	settextcolor(RGB(254,253,249));
	setbkcolor(RGB(244,186,1));//背景色
	outtextxy(216,535,"2048");//输出字符串2048

	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));//字体颜色
	setfont(30,0,"Microsoft Yahei Ul Boid");

}
void show2()
{
	cleardevice();//清屏
	RECT C2={60,60,640,790};
	drawtext("\n\n\n\n    游戏介绍：每次可以选择上下左右其中一个方向去滑动，每滑动一次，所有数字方块都会往滑动方向靠拢，系统也会在空白地方随机出现一个数字方块，相同数字会在靠拢碰撞时相加。不断的叠加，当最终拼凑出2048这个数字就算成功\n\n\n\n\n   开发者：冰炭不投day",&C2,DT_WORDBREAK);

	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("返回",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				return;
		}
	}
}

void show3()
{
	cleardevice();//清屏
	RECT C1={60,60,640,790};
	drawtext("\n\n\n操作说明：\n\n左移：A键/方向键←\n\n右移：D键/方向键→\n\n上移：W键/方向键↑\n\n下移：S键/方向键↓\n\n(返回：作者OS:你想得美 (￣^￣)ゞ)", &C1, DT_WORDBREAK);
	
	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("返回",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				return;
		}
	}
}

void show4()
{
	cleardevice();//清屏
	setfont(145,0,"Microsoft Yahei UI Bold");
	settextcolor(RGB(120,116,101));//设置字体
	outtextxy(15,0,"2048");

	setfillcolor(RGB(184,175,160));//设置当前填充颜色
	solidroundrect(390,10,530,80,15,15);//圆角梯形
	setfont(28,0,"Microsoft Yahei UI Bold");//设置当前字体
	setbkcolor(RGB(184,175,160));//背景颜色
	settextcolor(RGB(248,247,241));//字体颜色
	outtextxy(435,20,"得分");
	 
	char str[10],str_i[10];
	setbkcolor(RGB(184,175,160));
	itoa(score_i,str_i,10); 
	outtextxy(450,52,str_i);//分数

	solidroundrect(550,10,690,80,15,15);//圆角梯形
	outtextxy(600,20,"总分");
	setbkcolor(RGB(184,175,160));
	itoa(score,str,10); 
	outtextxy(610,52,str);//分数

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,95,690,137,15,15);
	setbkcolor(RGB(141,122,105));//背景颜色
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(525,100,"返回主页面");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,152,690,195,15,15);
	setbkcolor(RGB(141,122,105));//背景颜色
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(540,160,"重新开始");

	setfillcolor(RGB(187,173,160));
	solidroundrect(10,210,690,890,20,20);

	int i,j;
	for(i=0;i<4;i++)
	{
		setfillcolor(RGB(206,192,181));
		for(j=0;j<4;j++)
		{
			solidroundrect(30+165*i,230+165*j,175+165*i,375+165*j,5,5);
		}
	}
	IMAGE img0,img2,img4,img8,img16,img32,img64,img128,img256,img512,img1024,img2048;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			switch(map[j][i])
			{
				case 0:loadimage(&img0,"pic\\0.jpg");putimage(i*165+30,j*165+230,&img0);break;
				case 2:loadimage(&img2,"pic\\2.jpg");putimage(i*165+30,j*165+230,&img2);break;
				case 4:loadimage(&img4,"pic\\4.jpg");putimage(i*165+30,j*165+230,&img4);break;
				case 8:loadimage(&img8,"pic\\8.jpg");putimage(i*165+30,j*165+230,&img8);break;
				case 16:loadimage(&img16,"pic\\16.jpg");putimage(i*165+30,j*165+230,&img16);break;
				case 32:loadimage(&img32,"pic\\32.jpg");putimage(i*165+30,j*165+230,&img32);break;
				case 64:loadimage(&img64,"pic\\64.jpg");putimage(i*165+30,j*165+230,&img64);break;
				case 128:loadimage(&img128,"pic\\128.jpg");putimage(i*165+30,j*165+230,&img128);break;
				case 256:loadimage(&img256,"pic\\256.jpg");putimage(i*165+30,j*165+230,&img256);break;
				case 512:loadimage(&img512,"pic\\512.jpg");putimage(i*165+30,j*165+230,&img512);break;
				case 1024:loadimage(&img1024,"pic\\1024.jpg");putimage(i*165+30,j*165+230,&img1024);break;
				case 2048:loadimage(&img2048,"pic\\2048.jpg");putimage(i*165+30,j*165+230,&img2048);break;
			}
		}
	}

}
void rands()
{
	int x,y,temp,num;
	srand((int)time(0));
	while(1)
	{
		x=rand()%4;
		y=rand()%4;
		temp=rand()%5;
		if(temp==1)
			num=4;
		else 
			num=2;
		if(map[y][x]==0)
		{
			map[y][x]=num;
			break;
		}
	}
}
void updateWithInput()//与输入有关的更新
{
	char keyboard;
	if(kbhit())
	{	keyboard=getch(); 
		EndBatchDraw();//结束批量绘图
		score_i=0;
	}
	int i,j,n;
	if(keyboard=='w'||keyboard=='W'||keyboard==72)//上
	{
		for(n=0;n<4;n++)//次数
		for(i=1;i<4;i++)//行
		for(j=0;j<4;j++)//列
			if(map[i][j]!=0)
			{
				if(map[i-1][j]==0)
				{
					map[i-1][j]=map[i][j];
					map[i][j]=0;
				}
				if(map[i-1][j]==map[i][j])
				{
					score_i=map[i][j]*2;//得分
					score=score+score_i;
					map[i-1][j]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			rands();
	}
	else if(keyboard=='s'||keyboard=='S'||keyboard==80)//下
	{
		for(n=0;n<4;n++)//次数
		for(i=2;i>=0;i--)//行
		for(j=0;j<4;j++)//列
			if(map[i][j]!=0)
			{
				if(map[i+1][j]==0)
				{
					map[i+1][j]=map[i][j];
					map[i][j]=0;
				}
				if(map[i+1][j]==map[i][j])
				{
					score_i=map[i][j]*2;//得分
					score=score+score_i;
					map[i+1][j]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			rands();
	}
	else if(keyboard=='a'||keyboard=='A'||keyboard==75)//左
	{
		for(n=0;n<4;n++)//次数
		for(i=0;i<4;i++)//行
		for(j=1;j<4;j++)//列
			if(map[i][j]!=0)
			{
				if(map[i][j-1]==0)
				{
					map[i][j-1]=map[i][j];
					map[i][j]=0;
				}
				if(map[i][j-1]==map[i][j])
				{
					score_i=map[i][j]*2;
					score=score+score_i;
					map[i][j-1]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			rands();
	}
	else if(keyboard=='d'||keyboard=='D'||keyboard==77)//右
	{
		for(n=0;n<4;n++)//次数
		for(i=0;i<4;i++)//行
		for(j=2;j>=0;j--)//列
			if(map[i][j]!=0)
			{
				if(map[i][j+1]==0)
				{
					map[i][j+1]=map[i][j];
					map[i][j]=0;
				}
				if(map[i][j+1]==map[i][j])
				{
					score_i=map[i][j]*2;
					score=score+score_i;
					map[i][j+1]=map[i][j]*2;
					map[i][j]=0;
				}
			}
		rands();	
	}
	
}
void updateWithoutInput()//与输入无关的更新 
{

}

void start()
{
	
	MOUSEMSG m;
	int i,j;
	rands();
	rands();
	while(1)
	{
		show4();
		BeginBatchDraw();//批量画图，无闪烁
		setbkcolor(RGB(251,248,241));
		updateWithInput();//与输入有关的更新
		updateWithoutInput();//与输入无关的更新 
	}

}
int main (void)
{
	initgraph(WIDTH,HEIGHT);//长宽
	setbkcolor(RGB(251,248,241));//背景
	settextcolor(RGB(150,126,104));

	MOUSEMSG m;
	while(1)
	{
		show1();
		BeginBatchDraw();//批量绘图
		m=GetMouseMsg();//获取鼠标信息
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			EndBatchDraw();//结束批量绘图
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)
				start();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)
				show2();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+60&&m.y<HEIGHT/3+90)
				show3();
			
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+90&&m.y<HEIGHT/3+120)
				exit(0);
		}
	}
	getch();

}

