#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;
int x = 50;  //边界的x和y
int y = 20;
int birdx = x / 5;
int birdy = y / 4;
int speed = 0;//控制速度
int speed2 = 0;//控制障碍物的来临速度
int xx = x / 2;//障碍物的x坐标
int yy = rand() % (y / 2);

int num = 0;//记录笨鸟的得分


void notin();
void in();
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void show()//开始的初始化（达到循环显示的目的）
{
	gotoxy(0, 0);
	HideCursor();
	for (int i = 1; i < y; ++i)
	{
		for (int j = 1; j < x; ++j)
		{
			if (j == birdx && i == birdy)
			{
				cout << "\b" << "鸟"; //\b的作用是因为输出的汉字多占了一个大小的空间，\b删除之前一个位置的输出
			}
			else if (j == xx && (i >= 1 && i <= yy) || j == xx && (i >= yy + 5 && i <= y))
				cout << "*";

			else
				cout << " ";
		}
		cout << endl;
	}

	cout << "得分：" << num / 6 << endl;

}
void in()
{
	if (_kbhit())
	{
		string ss;
		ss = _getch();

		if (ss == " ")
		{
			if (birdy > 3)birdy -= 3;
		}


	}
}
void notin()  //改变小鸟的位置和障碍物的位置
{
	if (birdx == xx && (birdy >= yy && birdy <= yy + 5))
		num += 1;

	if (speed != 3)
	{
		speed++;
	}
	if (birdy != y && speed == 3)
	{
		birdy += 1;
		speed = 0;
	}


	if (speed2 != 5)
	{
		speed2++;
	}
	else if (speed2 == 5)
	{
		if (xx > 0)
		{
			xx--;

		}


		if (xx == 0)
		{
			xx = x / 2;//障碍物的x坐标
			yy = rand() % (y / 2);
			while (yy == 0)
			{
				yy = rand() % (y / 2);
			}

		}
		speed2 = 0;

	}



}
int main()
{
	while (yy == 0)
	{
		yy = rand() % (y / 2);
	}
	while (1)
	{


		show();
		notin();
		in();
		if (birdx == xx && (((birdy > 1 && birdy < yy)) || (birdy > yy + 5 && birdy < y)))
		{
			cout << "YOU ARE FILLED!!" << endl;
			break;
		}



	}
	return 0;
}
