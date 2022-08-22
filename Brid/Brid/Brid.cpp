//#include <iostream>
////#include<string>
////#include<time.h>
//#include<Windows.h>
//#include<cstdlib>
//#include<conio.h

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>

using namespace std;

int x = 50;  //边界的x和y
int y = 20;
int Pos_Brid_x = x / 5;
int Pos_Brid_y = y / 4;
int B_speed = 0;//控制速度
int obstacle_speed = 0;//控制障碍物的来临速度
int xx = x / 2;//障碍物的x坐标
int yy = rand() % (y / 2);


int score = 0;//记录分数

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
void Showbe()
{
	gotoxy(0, 0);
	HideCursor();
	for (int i = 1; i < y; ++i)
	{
		for (int j = 1; j < x; ++j)
		{
			if (j == Pos_Brid_x && i == Pos_Brid_y)
			{
				//\b的作用是因为输出的汉字多占了一个大小的空间，\b删除之前一个位置的输出
				cout <<"\b" << "鸟";
			}
			else if (j == xx && (i >= 1 && i <= yy) || j == xx && (i >= yy + 5 && i <= y))
			
				cout << "*";
			
			else
			
				cout << " ";
			
		}
		cout << endl;
	}
	cout <<"得分"<< score/6 << endl;
}

void in()
{
	if (_kbhit())
	{
		string ss;
		ss = _getch();

		if (ss == " ")
		{
			if (Pos_Brid_y > 3)
				Pos_Brid_y -= 3;
		}


	}
}

void notin()
{
	if (Pos_Brid_x == xx && (Pos_Brid_y >= yy && Pos_Brid_y <= yy + 5))
		score += 1;

	if (B_speed != 5)
	{
		B_speed++;
	}
	if (Pos_Brid_y != y && B_speed == 5)
	{
		Pos_Brid_y += 1;
		B_speed = 0;
	}


	if (obstacle_speed != 5)
	{
		obstacle_speed++;
	}
	else if (obstacle_speed == 5)
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
	obstacle_speed = 0;
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


		Showbe();
		notin();
		in();
		if (Pos_Brid_x == xx && (((Pos_Brid_y > 1 && Pos_Brid_y < yy)) || (Pos_Brid_y > yy + 5 && Pos_Brid_y < y)))
		{
			cout << "YOU ARE FILLED!!" << endl;
			break;
		}

	}
		return 0;
}
