#pragma once

#include<stdio.h>
#include<stdlib.h>


#define DIV_LINE printf("\n\n===========%s==========\n\n",__FUNCTION__);

typedef char TypeChar;

typedef struct LinkNode
{
	TypeChar data;
	struct LinkNode *next;
}LinkNode;

//�Ե�������г�ʼ��
void InitLinkNode(LinkNode **head);

//��ӡ
void LinkNodePrint(LinkNode *head);

//�����ڵ�
LinkNode *CreatNode(TypeChar value);

//�Ե��������β��;
LinkNode* PushBackLinkNode(LinkNode** head, TypeChar Value);

//�Ե��������βɾ
void PopBackLinkNode(LinkNode** head);

//�Ե��������ͷ��
void PushFrontLinkNode(LinkNode** head, TypeChar Value);

//�Ե��������ͷɾ
void PopFrontLinkNode(LinkNode** head);

//�Ե��������ֵλ�õĲ��ң����ض�Ӧֵ�ĵ�ַ
LinkNode* FindLinkNode(LinkNode* head, TypeChar value);

//�������ָ��λ��֮ǰ����Ԫ�أ���ͨ�ŷ���,ʱ�临�Ӷ�O(n)
void InsertFrontLinkNode(LinkNode** head, LinkNode* pos, TypeChar value);

//�������ָ��λ��֮ǰ����Ԫ�ء����ƻ���ľ�󷨣�ʱ�临�Ӷ�Ϊo(1).
void InsertFrontLinkNode1(LinkNode** head, LinkNode* pos, TypeChar value);

//�ڵ�����ָ��λ��֮�����Ԫ�ء�
void InsertAfterLinkNode(LinkNode* head, LinkNode* pos, TypeChar value);

//ɾ��������������ָ��λ�õĽڵ㡣ʱ�临�Ӷ�Ϊo(n)
void EraseLinkNode(LinkNode** head, LinkNode* pos);

//ɾ����������ָ��λ�õĽڵ㣬������β�ڵ㣩ʱ�临�Ӷ�Ϊo(1).
void EraseLinkNode1(LinkNode* head, LinkNode* pos);

//ɾ��ָ��ֵ�Ľڵ㣬������ͷ�������е�һ�����ֵ�ֵ�Ľڵ㣩
void RemoveLinkNode(LinkNode** head, TypeChar value);

//ɾ��ָ��ֵ������Ԫ�ء�
void RemoveLinkNodeAll(LinkNode** head, TypeChar value);

//�ж������Ƿ�Ϊ��
int EmotyLinkNode(LinkNode* head);

//��������
size_t SizeLinkNode(LinkNode* head);

//�����������ӡ
void BackPrintLinkNode(LinkNode* head);