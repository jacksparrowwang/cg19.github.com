#pragma once

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define FOOD "��"
#define SNAKE_FOOD "��"
#define INIT_X 24
#define INIT_Y 10

//�ߵ�����
typedef struct node
{
	int x;
	int y;
	struct node *next;
}node;

//״̬
enum status
{
	OK,
	KILL_BY_WALL,
	KILL_BY_OWN
};

//����
enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

//��
typedef struct snake
{
	node *head;
	node *food;
	enum status sta;
	enum direction dir;
	int speed;
}snake;

//��ӭ����
void welcome();

//���λ��
void SetPos(int x,int y);

//������ͼ
void CreatMap();

//��ʼ����
void InitSnake(snake *ps);

//��ʼ��ʳ��
void InitFood(snake *ps);

//���ƶ�
void SnakeMove(snake *ps);

//��ʳ�����
void EatFood(snake *ps,node *snf);

//û��ʳ�����
void NoFood(node **sn,node *mov);