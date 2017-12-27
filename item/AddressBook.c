
#define _CRT_SECURE_NO_WARNINGS

#include "AddressBook.h"

//��ʼ��ͨѶ¼
void address_book_init(address_book *book)
{
	if(book == NULL)
	{
		return ;
	}
	book->size = 0;
}

//�����Ϣ
void address_book_add(address_book *book)
{
	size_t cur = 0;
	if(book == NULL)
	{
		printf("book is NULL\n");
		return ;
	}
	cur = book->size;
	++book->size;
	printf("�����Ϣ\n");
	printf("������Ҫ��ӵ�����\n");
	scanf("%s",book->data[cur].name);
	printf("������Ҫ��ӵ��Ա�\n");
	scanf("%s",book->data[cur].gender);
	printf("������Ҫ��ӵĵ绰\n");
	scanf("%s",book->data[cur].number);
	printf("������Ҫ��ӵĵ�ַ\n");
	scanf("%s",book->data[cur].address);
	printf("��ӳɹ�\n");
	return;
}

//��ʾ��Ϣ
void address_book_display(address_book *book)
{
	size_t j = 0;
	if(book == NULL)
	{
		return ;
	}
	printf("���\t\t����\t\t�Ա�\t\t�绰\t\t��ַ\n");
	for(j=0; j< book->size; j++)
	{
		printf("%u\t\t%s\t\t%s\t\t%s\t\t%s\n",j,book->data[j].name,
		book->data[j].gender,book->data[j].number,
		book->data[j].address);
	}
}

//������Ϣ
void address_book_save(address_book *book)
{
	size_t i = 0;
	FILE *fp = fopen(FILE_PATH,"w");
	if(book == NULL)
	{
		return ;
	}
	if(fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return ;
	}
	//fprintf(fp,"���\t\t����\t\t�Ա�\t\t�绰\t\t��ַ\n");
	for(i=0; i< book->size; i++)
	{
		fprintf(fp,"%u\t\t%s\t\t%s\t\t%s\t\t%s\n",i,book->data[i].name,
		book->data[i].gender,book->data[i].number,
		book->data[i].address);
	}
	fclose(fp);
}

//������Ϣ
void address_book_load(address_book *book)
{
	size_t len = 0;
	size_t i = 0;
	FILE *fp = fopen(FILE_PATH,"r");

	if(book == NULL)
	{
		return ;
	}
	if(fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return ;
	}
	fseek(fp,0,SEEK_END);
	len = ftell(fp);
	if(len == 0)
	{
		printf("ͨѶ¼Ϊ��\n\n");
		return ;
	}
	rewind(fp);
	while(!feof(fp))
	{
		fscanf(fp,"%u\t\t%s\t\t%s\t\t%s\t\t%s\n",&i,book->data[book->size].name,//name�����飬�ڵ���������ʱ�򽵼�Ϊָ��
			book->data[i].gender,book->data[book->size].number,
			book->data[book->size].address);
		i++;
		++book->size;
	}
	fclose(fp);
}


//�޸���Ϣ
void address_book_update(address_book *book)
{
	size_t i = 0;
	if(book == NULL)
	{
		return ;
	}
	printf("������Ҫ�޸ĵı��\n");
	scanf("%u",&i);
	if(i > book->size || i < 0)
	{
		printf("����Ϊ�Ƿ�ֵ\n");
		return ;
	}
	printf("�޸���Ϣ\n");
	printf("�����޸�Ϊ\n");
	scanf("%s",book->data[i].name);
	printf("�Ա��޸�Ϊ\n");
	scanf("%s",book->data[i].gender);
	printf("�޸ĵ绰Ϊ\n");
	scanf("%s",book->data[i].number);
	printf("��ַ�޸�Ϊ\n");
	scanf("%s",book->data[i].address);
	printf("�޸ĳɹ�\n");
	return ;
}


//ɾ����Ϣ
void address_book_delete(address_book *book)
{
	size_t i = 0;
	if(book == NULL)
	{
		return ;
	}
	printf("������Ҫɾ���ı��\n");
	scanf("%u",&i);
	if(i > book->size)
	{
		printf("����Ϊ�Ƿ�ֵ\n");
		return ;
	}
	while(i < book->size)
	{
		book->data[i] = book->data[i+1];
		i++;
	}
	book->size--;
	printf("ɾ���ɹ�\n");
	return;
}

//ɾ��������Ϣ
void address_book_delete_all(address_book *book)
{
	if(book == NULL)
	{
		return ;
	}
	book->size = 0;
}

//������Ϣ
void address_book_find(address_book *book)
{
	int flag = 0;
	size_t i = 0;
	int choice = 0;
	char f_name[50];
	char f_number[50];
	if(book == NULL)
	{
		//bookΪ��ָ�룻
		return ;
	}
	printf("������Ҫ���ҵķ�ʽ\n");
	printf("************************\n");
	printf("*1.�������� 2.�绰�Ų���\n");
	printf("************************\n");
	scanf("%d",&choice);
	if (choice == 1)
	{
		//��������
		printf("��������ҵ��������߹ؼ���\n");
		scanf("%s",f_name);
		printf("���\t\t����\t\t�Ա�\t\t�绰\t\t��ַ\n");
		while(i < book->size)
		{
			if(strstr(book->data[i].name,f_name)) //��strstr��������ؼ���
			{
				flag = 1;
				printf("%u\t\t%s\t\t%s\t\t%s\t\t%s\n",i,book->data[i].name,
				book->data[i].gender,book->data[i].number,
				book->data[i].address);
			}
			i++;
		}
		if(flag == 0)
		printf("δ���ҵ�\n");
	}
	else if (choice == 2)
	{
		//�绰�������
		printf("��������ҵĵ绰�Ż��߹ؼ�����\n");
		scanf("%s",f_number);
		printf("���\t\t����\t\t�Ա�\t\t�绰\t\t��ַ\n");
		while(i < book->size)
		{
			if(strstr(book->data[i].number,f_number))
			{
				flag = 1;
				printf("%u\t\t%s\t\t%s\t\t%s\t\t%s\n",i,book->data[i].name,
				book->data[i].gender,book->data[i].number,
				book->data[i].address);
			}
			i++;
		}
		if(flag == 0)
		{
			printf("δ���ҵ�\n");
		}
	}
	else
	{
		printf("ѡ�����\n");
	}
}

/*fseek(fp,100L,0);���ļ��ڲ�ָ���ƶ������ļ���ͷ100�ֽڴ���
fseek(fp,100L,1);���ļ��ڲ�ָ���ƶ������ļ���ǰλ��100�ֽڴ���
fseek(fp,-100L,2);���ļ��ڲ�ָ���˻ص����ļ���β100�ֽڴ���

ftell(fp);���ú��� ftell() Ҳ�ܷ����֪��һ���ļ��ĳ���
������������У� fseek(fp, 0L,SEEK_END); len =ftell(fp)+1; 
���Ƚ��ļ��ĵ�ǰλ���Ƶ��ļ���ĩβ��Ȼ����ú���ftell()��õ�ǰ
λ��������ļ��׵�λ�ƣ���λ��ֵ�����ļ������ֽ�����
*/

//����ͨѶ¼
void adderss_book_destory(address_book *book)
{
	FILE *fp = fopen(FILE_PATH,"w");
	if(book == NULL)
	{
		return ;
	}
	if(fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return ;
	}
	fseek(fp,0,SEEK_SET);
	rewind(fp);
	fclose(fp);
	printf("���ٳɹ�\n");
}


enum
{
	EXIT,
	DISPLAY,
	ADD,
	UPDATE,
	Y_DELETE,
	FIND,
	DESTORY
};

//�˵�
void menu()
{
	int choice = 0;
	address_book book;
	address_book_init(&book);
	address_book_load(&book);
	while(1)
	{
		printf("===============================\n");
		printf("1.��ʾͨѶ¼\n");
		printf("2.���\n");
		printf("3.�޸�\n");
		printf("4.ɾ��\n");
		printf("5.����\n");
		printf("6.����\n");
		printf("0.�˳�\n");
		printf("===============================\n");
		scanf("%d",&choice);
		system("cls");
		switch (choice)
		{
			case DISPLAY:
				address_book_display(&book);
				break;
			case ADD:
				address_book_add(&book);
				address_book_save(&book);
				break;
			case UPDATE:
				address_book_update(&book);
				address_book_save(&book);
				break;
			case Y_DELETE:
				address_book_delete(&book);
				address_book_save(&book);
				break;
			case FIND:
				address_book_find(&book);
				break;
			case DESTORY:
				adderss_book_destory(&book);
				address_book_delete_all(&book);
				break;
			case EXIT:
				return ;
				break;
			default:
				printf("����ֵ�Ƿ�\n");
				break;
		}
	}

}

int main()
{
	menu();
	return 0;
}