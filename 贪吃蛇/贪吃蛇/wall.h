#pragma once

//ǽ��������Ҫά��һ����ά���飬��������Ϸ�е�Ԫ�ؽ������ã�������������һ����ά���飬   char GameArray��������
//�����������������Զ����һ��ö�٣���������25,25   enum{ ROW=25,COL=25}
//ǽ��Ҫ�Ľӿڡ�

#include<iostream>
#include<vector>
using  namespace std;

class Wall
{
public:
	//ö��������������
	enum {
		ROW = 45,
		COL=45
	};
	//��ʼ��ǽ�ڡ�
	void initWall();
	//��ǽ��
	void drawWall();
	//������������ ��ά��������ݡ�
	void setWall(int x, int y, char c);
	//������������ȡ��ǰλ�õķ��š�
	char getWall(int x, int y);


private:

	char gameArray[ROW][COL];


};
