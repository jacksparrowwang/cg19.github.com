#pragma once

#include<stdio.h>

typedef char SearchTreeType;

typedef struct SearchTreeNode{
	SearchTreeType data;
	struct SearchTreeNode *lchild;
	struct SearchTreeNode *rchild;
}SearchTreeNode;

// ��ʼ����
void SearchTreeInit(SearchTreeNode **root);

// �������Ĳ���
void SearchTreeInsert(SearchTreeNode **root, SearchTreeType value);

// �������е�ĳ��Ԫ�ص�λ��
SearchTreeNode *SearchTreeFind(SearchTreeNode *root, SearchTreeType to_find);

// ɾ������ĳ��Ԫ��
void SearchTreeRemove(SearchTreeNode **root, SearchTreeType value);