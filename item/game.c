#include"game.h"
void init(char mine[ROWS][COLS],char set)//��ʼ��  ����  ����
{
	int i, j;
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			mine[i][j] = set;
		}
	}
}
void display_mine(char mine[ROWS][COLS],int rows,int cols)//��ӡ��
{
	int i, j;
	
	//printf("��Ϸ��ʼ\n");
	//printf("");
	for(i=1; i<=ROW; i++)
	{
		printf("%4d",i);
	}
	printf("\n");
	for(i=1; i<=ROW; i++)
	{
		printf("%2d ",i);
		for(j=1; j<=COL; j++)
		{
			printf("%c   ",mine[i][j]);
		}
		printf("\n");
	}
}
void display_check(char show[ROWS][COLS],int rows,int cols)//��ӡ����
{
	int i, j;
	system("cls");
	printf("��Ϸ��ʼ\n");
	
	for(i=1; i<=ROW; i++)
	{
		printf("%4d",i);
	}
	printf("\n");
	for(i=1; i<=ROW; i++)
	{
		printf("%2d ",i);
		for(j=1; j<=COL; j++)
		{
			printf("%c   ",show[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char mine[ROWS][COLS],int row,int col,int count)//����
{
	int x = 0,y = 0;
	while(count>0)
	{
		x = rand()%row+1;
		y = rand()%col+1;
		if(mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
		
	}
}
int sweep_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int count)//ɨ��
{
	int x = 0,y = 0,c = 0,n = 1,select = 0,num = 0;
	while(ROW*COL-count >= n&&num<=count)//�����Ӯ
	{
		
		printf("1 ����  2 �����  3 ȡ�����\n");
		printf("---------------------------\n");
		printf("��ѡ��--��\n");
		scanf("%d",&select);//ѡ��ɨ��  �����  ȡ�����
		if(select == 1)
		{
			printf("�������� ��--��\n");
			scanf("%d%d",&x,&y);
			if(x>0&&x<=row&&y>0&&y<=col)//�жϴ���ֵ�Ƿ�Ϸ�
			{

				if(n==1 && mine[x][y] == '1')
				{
					mine[x][y] = '0';
					repeat_frist_mine(mine,x,y);//�ѵ�һ���׸�����
				}
				//show[x][y] = mine[x][y];
				if(mine[x][y] == '1')//������
				{
					show[x][y] = '@';
					return 1;
				}
				else
				{
					expand(mine,show,x,y);//��������չ
				}
				display_check(show,ROWS,COLS);
			}
			else
			{
				printf("�������,����������\n");
			}
			n++;
		}
		else if(select == 2)
		{
			printf("������Ҫ��ǵ��� ��\n");
			scanf("%d%d",&x,&y);
			mark_mine(show,x,y);
			num++;
			
		}
		else if(select == 3)
		{
			printf("������Ҫȡ����ǵ��� ��\n");
			scanf("%d%d",&x,&y);
			cancel_mark_mine(show,x,y);
			num--;
			
		}
		else
		{
			printf("����������\n");
		}
	}
	return 0;
}
int around_mine_amount(char mine[ROWS][COLS],int x,int y)//�Ƿ���static?  ������Χ��
{
	int amount = 0;
	amount = (mine[x-1][y]+mine[x-1][y-1]+mine[x][y-1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]+mine[x][y+1]+mine[x-1][y+1])-'0'*8;
	return amount;
}
void repeat_frist_mine(char mine[ROWS][COLS],int x,int y)//�������õ�һ����
{
	int i = 0;
	int j = 0;

	do
	{
		i = rand()%10+1;
		j = rand()%10+1;
		if(mine[i][j] != '1'&& i != x && j != y)
		{
			mine[i][j] = '1';
			break;
		}
	}
	while(1);
}


void expand(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y)//��չ
{
	if(x>0 && x<=ROW && y>0 && y<=COL)
	{
		if(around_mine_amount(mine,x,y) == 0)
		{
			show[x][y] = '0';
			if(mine[x-1][y] == '0' && show[x-1][y] == '*')//1
			{
				expand(mine,show,x-1,y);
			}
			else
			{
				show[x-1][y] = around_mine_amount(mine,x-1,y) + '0';
			}
			if(mine[x-1][y+1] == '0'&& show[x-1][y+1] == '*')//2
			{
				expand(mine,show,x-1,y+1);
			}
			else
			{
				show[x-1][y+1] = around_mine_amount(mine,x-1,y+1) + '0';
			}
			if(mine[x][y+1] == '0'&& show[x][y+1] == '*')//3
			{
				expand(mine,show,x,y+1);
			}
			else
			{
				show[x][y+1] = around_mine_amount(mine,x,y+1) + '0';
			}
			if(mine[x+1][y+1] == '0'&& show[x+1][y+1] == '*')//4
			{
				expand(mine,show,x+1,y+1);
			}
			else
			{
				show[x+1][y+1] = around_mine_amount(mine,x+1,y+1) + '0';
			}
			if(mine[x+1][y] == '0'&& show[x+1][y] == '*' )//5
			{
				expand(mine,show,x+1,y);
			}
			else
			{
				show[x+1][y] = around_mine_amount(mine,x+1,y) + '0';
			}
			if(mine[x+1][y-1] == '0'&& show[x+1][y-1] == '*')//6
			{
				expand(mine,show,x+1,y-1);
			}
			else
			{
				show[x+1][y-1] = around_mine_amount(mine,x+1,y-1) + '0';
			}
			if(mine[x][y-1] == '0'&& show[x][y-1] == '*')//7
			{
				expand(mine,show,x,y-1);
			}
			else
			{
				show[x][y-1] = around_mine_amount(mine,x,y-1) + '0';
			}
			if(mine[x-1][y-1] == '0'&& show[x-1][y-1] == '*')//8
			{
				expand(mine,show,x-1,y-1);
			}
			else
			{
				show[x-1][y-1] = around_mine_amount(mine,x-1,y-1) + '0';
			}
		}
		else
		{
			show[x][y] = around_mine_amount(mine,x,y) + '0';
		}
	}
}
void mark_mine(char show[ROWS][COLS],int x,int y)//�����
{
	if(show[x][y] == '*')
	{
		show[x][y] = '$' ;
		display_check(show,ROWS,COLS);
	}
	else
	{
		printf("���λ�ô���\n");
	}
}


void cancel_mark_mine(char show[ROWS][COLS],int x,int y)//ȡ�����
{
	if(show[x][y] == '$')
	{
		show[x][y] = '*' ;
		display_check(show,ROWS,COLS);
	}
	else
	{
		printf("ȡ�����λ�ô���\n");
	}
}