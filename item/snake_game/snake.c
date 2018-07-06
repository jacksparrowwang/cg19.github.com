#include "snake.h"
#include<windows.h>



//��ӭ����
void welcome()
{
	SetPos(20,10);
	printf("welcome to snake game\n");
	SetPos(18,16);
	printf("�� �� �� �� ���Ʒ���\n");
	system("pause");
	system("cls");
}

//�ƶ����λ��
void SetPos(int x,int y)
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//�����������λ��
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
}


//������ͼ
void CreatMap()
{
	int i = 0;
	for (i=0; i <= 56; i+=2)
	{
		SetPos(i,0);
		printf(FOOD);
		SetPos(i,26);
		printf(FOOD);
	}
	for(i=1; i <= 25; i++)
	{
		SetPos(0,i);
		printf(FOOD);
		SetPos(56,i);
		printf(FOOD);
	}
}

//��ʼ����
void InitSnake(snake *ps)
{
	int i = 0;
	
	node *cur = NULL;
	if(ps == NULL)
	{
		printf("node is NULL");
		return;
	}
	cur = (node*)malloc(sizeof(node));//�����ߵ�β�ڵ�
	cur->next = NULL;
	cur->x = INIT_X;
	cur->y = INIT_Y;
	for(i=1; i<=4; i++)//��ͷ������д���������
	{
		ps->head = (node*)malloc(sizeof(node));
		ps->head->next = cur;
		ps->head->x = INIT_X + i*2;
		ps->head->y = INIT_Y;
		cur = ps->head;
	}
	ps->sta = OK;
	ps->dir = RIGHT;
	ps->speed = 300;
	while(cur != NULL)
	{
		SetPos(cur->x,cur->y);
		printf(SNAKE_FOOD);
		cur = cur->next;
	}
	printf("\n");

}

//��ʼ��ʳ��
void InitFood(snake *ps)
{
	node *cur = ps->head;
	if (ps == NULL)
	{
		return;
	}
	ps->food = (node*)malloc(sizeof(node));//����ʧ��
	ps->food->next = NULL;
agine :
	do
	{
		ps->food->x = rand() % 53 + 2;
	}while(ps->food->x%2 != 0);//����ʧ������������λ����
	ps->food->y = rand() % 25 + 1;
	while(cur != NULL)
	{
		if(cur->x == ps->food->x && cur->y == ps->food->y)
		{
			goto agine;
		}
		cur = cur->next;
	}
	SetPos(ps->food->x,ps->food->y);
	printf(SNAKE_FOOD);
	
}

//��ʳ�����
void EatFood(snake *ps,node *snf)
{
	//�������ڵ�mov�ڵ���뵽ͷ��������ͷָ��
	node *cur = NULL;
	snf->next = ps->head;
	ps->head = snf;
	cur = ps->head;
	while(cur != NULL)//���´�ӡ������ɾ�����һ���ڵ�
	{
		SetPos(cur->x,cur->y);
		printf(SNAKE_FOOD);
		cur = cur->next;
	}
	InitFood(ps);
}

//û��ʳ�����
void NoFood(node **sn,node *mov)
{
	//�������ڵ�mov�ڵ���뵽ͷ��������ͷָ��
	node *cur = NULL;
	mov->next = *sn;
	*sn = mov;
	cur = *sn;
	while(cur->next->next != NULL)//���´�ӡ
	{
		SetPos(cur->x,cur->y);
		printf(SNAKE_FOOD);
		cur = cur->next;
	}
	SetPos(cur->next->x,cur->next->y);//������һ���ڵ��Ϊ�ո񣬲���������ڵ�
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

//���ƶ�
void SnakeMove(snake *ps)
{
	node *cur = (node *)malloc(sizeof(node));//�����ڵ�Ϊû�Ե�ʳ��ʱ���ƶ�
	cur->x = ps->head->x;
	cur->y = ps->head->y;

	//�������ת��
	switch(ps->dir)
	{
	case UP:
		cur->y -= 1;
		break;
	case DOWN:
		cur->y += 1;
		break;
	case LEFT:
		cur->x -= 2;
		break;
	case RIGHT:
		cur->x += 2;
		break;
	default:
		break;
	}
	if(ps->food->x == ps->head->x && ps->food->y == ps->head->y)//�ж��Ƿ�����ʧ��
	{
		EatFood(ps,ps->food);
	}
	else
	{
		NoFood(&ps->head,cur);
	}
}

//��ǽײ��
void KillByWall(snake *ps)
{
	//�жϱ߽�
	if(ps->head->x == 0 || ps->head->x == 56 || ps->head->y == 0 || ps->head->y == 26)
	{
		ps->sta = KILL_BY_WALL;
	}
}

//�Ե��Լ�
void KillByOwn(snake *ps)
{
	node *cur = ps->head->next->next;//ͷ�ڵ�ĺ��һ���ڵ㣬�ڶ��ڵ㲻���жϣ���Ϊͷ�Բ����ڶ���
	while(cur != NULL)
	{
		if(ps->head->x ==cur->x  && ps->head->y == cur->y)//�����Լ���ͷ�ڵ��x,y
		{
			ps->sta = KILL_BY_OWN;
			break;
		}
		cur = cur->next;
	}
}

//��Ϸ������ʾ
void EndGame(snake *ps)
{
	SetPos(22,13);
	switch(ps->sta)
	{
	case  KILL_BY_OWN:
		printf("���Լ����Լ��Ե���\n");
		break;
	case KILL_BY_WALL:
		printf("�㱻ǽײ����\n");
		break;
	default:
		break;;
	}
}

//��Ϸ����
void SnakeControl(snake *ps)
{
	do
	{
		//������̵�������
		if (GetAsyncKeyState(VK_UP) && ps->dir != DOWN)
		{
			ps->dir = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && ps->dir != UP)
		{
			ps->dir = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && ps->dir != RIGHT)
		{
			ps->dir = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && ps->dir != LEFT)
		{
			ps->dir = RIGHT;
		}
		Sleep(ps->speed);//�ߵ��ٶ�
		SnakeMove(ps);
		KillByWall(ps);
		KillByOwn(ps);
		
	}while(ps->sta == OK);
	EndGame(ps);
}

void GameRun()
{
	snake s;
	welcome();
	srand((int)time(NULL));
	CreatMap();
	InitSnake(&s);
	InitFood(&s);
	SnakeControl(&s);
	
}

int main()
{
	GameRun();
	return 0;
}