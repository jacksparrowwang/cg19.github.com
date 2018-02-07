#pragma once

#include<stdio.h>
#include<malloc.h>
//#ifndef __D_SEQLIST_H__
//#define __D_SEQLIST_H__
//#endif 

typedef char CHAR;

typedef struct seqlist
{
	CHAR *elem;
	size_t size;
	size_t capacity;
}seqlist;

seqlist seq;

//��ӡ˳���
void seqlist_print(seqlist *seq);

//�Զ�̬˳���ĳ�ʼ��
void seqlist_init(seqlist *seq);

//����˳����β��
void seqlist_push_back(seqlist *seq,CHAR value);

//������������
void seqlist_expand_capacity(seqlist *seq);

//��˳��������
void seqlist_destroy(seqlist *seq);


