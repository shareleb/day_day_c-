#pragma once
#include"wall.h"
#include"food.h"
#include<iostream>
using namespace std;

class Snake
{


	struct Point
	{
		//������
		int x;
		int y;
		//ָ����
		Point * next;
	};
	Point * pHead;
	Wall & wall;
	Food & food;
	bool isRool;  //�ж�ѭ���ı�־
public:

	enum
	{
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
	};
	//���캯��
	Snake(Wall &tempWall,Food & tempFood);

	//��ʼ����
	void initSnake();

	//���ٽڵ�
	void  destroyPoint();

	//��ӽڵ�
	void addPoint(int x, int y);

	//ɾ���ڵ�
	void delPoint();


	//�ƶ��߲���
	//����ֵ�����ƶ��Ƿ�ɹ���
	bool move(char key);



	//�趨�Ѷ�

	//��ȡˢ��ʱ��
	int getSleepTime();
	//��ȡ�����
	int countList();

	//��ȡ����
	int getScore();

};
