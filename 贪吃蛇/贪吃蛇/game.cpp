#include<iostream>
#include<vector>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
using  namespace std;

//��#include<Windows.h> ��  ֻҪ���þ����ˣ����ü�  ��ֱ����  ���ƹ�궨λ
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);

}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ�����������



int main()
{
	//���������ӡ�
	srand((unsigned)time(NULL));
	
	//�Ƿ�������ʶ��
	bool isDead = false;
	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();
	/*snake.move('w');
	snake.move('w');
	snake.move('a');*/

	gotoxy(hOut, 0, Wall::ROW);
	cout << "�÷֣�" << snake.getScore() << "��" << endl;
	

	//gotoxy(hOut,10, 5);


	//�����û�������
	while (true)
	{
		char key = _getch();
		//�ж�����ǵ�һ�ΰ�������� ���ܼ�����Ϸ
		//�ж���һ���ƶ�����
		if (preKey==NULL&&key == snake.LEFT)
		{
			continue;
		}
		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//�жϱ��ΰ����Ƿ����ϴγ�ͻ
				if (key == snake.LEFT&&preKey == snake.RIGHT ||
					key == snake.RIGHT&&preKey == snake.LEFT ||
					key == snake.UP&&preKey == snake.DOWN ||
					key == snake.DOWN&&preKey == snake.UP)
				{
					key = preKey;   // 
				}
				else
				{
					preKey = key;   //����ͻ���Ը��°���
				}
				
				if (snake.move(key) == true)
				{
					//�ƶ��ɹ� ����
				//	system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);

					cout << "�÷֣�" << snake.getScore() << "��" << endl;
					Sleep(snake.getSleepTime());     //����
					
				}
				else
				{
					isDead = true;
					break;
				}

			}
			else
			{
				key = preKey;    //ǿ�ƽ����󰴼������ ��һ���ƶ��ķ���
			}

		} while (!_kbhit());   //��û�м��������ʱ�򣬷���0
		if (isDead == true)
		{
			break;
		}
	}
	

	////���ԡ�
	//wall.setWall(5, 4, '=');
	//wall.setWall(5, 5, '=');
	//wall.setWall(5, 6, '@');

	system("pause");
	return EXIT_SUCCESS;
}