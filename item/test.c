#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
	printf("��ѡ��--��\n");
}
void test()
{
	int ret = 0;
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	srand((unsigned int)time(NULL));

	init(mine,'0');//��ʼ������
	//display_mine(mine,ROWS,COLS);
	set_mine(mine,ROW,COL,EASY);//������
	//display_mine(mine,ROWS,COLS);
	init(show,'*');//��ʼ������
	display_check(show,ROWS,COLS);//��ӡ����
	ret = sweep_mine(mine,show,ROW,COL,EASY);//ɨ��
	if(ret == 1)
	{
		printf("���ź��㱻ը����  @  \n");
	}
	else 
	{
		printf("��ϲ�㣬ʤ����\n");
	}
	display_check(show,ROWS,COLS);
	
	printf("*****�׵ķֲ� 1 *****\n");
	
	display_mine(mine,ROWS,COLS);
}

int main()
{
	int input = 0;	
	do
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
		case PLAY:
			printf("��Ϸ��ʼ\n");
				 test();
			printf("��Ϸ����\n");
			break;
		case EXIT:
			break;
		default:
			printf("�������\n");
			break;
		}
	}
	while(input);//�������Ϸ������������֣�������ѭ������ô�����
	return 0;
}