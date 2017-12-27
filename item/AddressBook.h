#ifndef __ADDRESSBOOK_H__
#define __ADDRESSBOOK_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define NAME_MAX 200
#define GENDER_MAX 100
#define ADDRESS_MAX 200
#define NUMBER_MAX 200
#define SEQLIST_MAX 1000
#define FILE_PATH "address_book.txt"

typedef struct person_inf
{	
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	char number[NUMBER_MAX];
	char address[ADDRESS_MAX];
}person_inf;

typedef struct address_book
{
	size_t size;
	person_inf data[SEQLIST_MAX];
}address_book;

//��ʼ��ͨѶ¼
void address_book_init(address_book *book);

//�����Ϣ
void address_book_add(address_book *book);

//��ʾ��Ϣ
void address_book_display(address_book *book);

//ɾ��������Ϣ
void address_book_delete_all(address_book *book);

//������Ϣ
void address_book_save(address_book *book);

//������Ϣ
void address_book_load(address_book *book);

//�޸���Ϣ
void address_book_update(address_book *book);

//ɾ����Ϣ
void address_book_delete(address_book *book);

//������Ϣ
void address_book_find(address_book *book);

//����ͨѶ¼
void adderss_book_destory(address_book *book);

#endif