#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

#define WIDTH 700
#define HEIGHT 900

int score;
void o1();
void o2();
void o3();
void start();

void lead()
{
	initgraph(WIDTH,HEIGHT);//长宽
	setbkcolor(RGB(251,248,241));//背景
	settextcolor(RGB(150,126,104));
	o1();
}
void o1()
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

	MOUSEMSG m;
	while(1)
	{
		BeginBatchDraw();//批量绘图
		m=GetMouseMsg();//获取鼠标信息
		if(m.uMsg==WM_LBUTTONDOWN)
		{

				EndBatchDraw();//结束批量绘图
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)
				start();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)
				o2();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+60&&m.y<HEIGHT/3+90)
				o3();
			
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+90&&m.y<HEIGHT/3+120)
				exit(0);
		}
	}
	getch();

}
void o2()
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
				o1();
		}
	}
}
void o3()
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
				o1();
		}
	}

}
void start()
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
	outtextxy(435,20,"分数");
	 
	solidroundrect(550,10,690,80,15,15);//圆角梯形
	outtextxy(590,20,"最高分");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,95,690,137.5,15,15);
	setbkcolor(RGB(141,122,105));//背景颜色
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(525,100,"返回主页面");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,152.5,690,195,15,15);
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

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			initgraph(WIDTH,HEIGHT);//长宽
			setbkcolor(RGB(251,248,241));//背景
			settextcolor(RGB(150,126,104));
			if(m.x>480&&m.x<690&&m.y>95&&m.y<137.5)
				o1();

			if(m.x>480&&m.x<690&&m.y>152.5&&m.y<195)
				start();
		}
	}

}
int main(void)
{
	
	lead();
}
