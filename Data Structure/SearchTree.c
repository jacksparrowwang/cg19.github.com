#include"SearchTree.h"
#include<windows.h>

void DestroyTreeNode(SearchTreeNode *delete)
{
	if (delete == NULL)
	{
		return;
	}
	free(delete);
}

// ��ʼ��
void SearchTreeInit(SearchTreeNode **root)
{
	if (root == NULL)
	{
		return;
	}
	*root = NULL;
}

// �������ڵ�
SearchTreeNode *CreatSearchTree(SearchTreeType value)
{
	SearchTreeNode *new_node = (SearchTreeNode *)malloc(sizeof(SearchTreeNode));
	new_node->data = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

#if 1
// �����������Ĳ��루�ǵݹ飩
void SearchTreeInsert1(SearchTreeNode **root, SearchTreeType value)
{
	if (root == NULL)
	{
		return;
	}
	//����Ϊ������
	if (*root == NULL)
	{
		*root = CreatSearchTree(value);
		return;
	}
	SearchTreeNode *parent = NULL;
	SearchTreeNode *cur = *root;
	// ���ҵ�Ҫ�����λ�á�������Ҫ��¼��ǰ�ڵ�ĸ��ڵ㡣
	while (cur != NULL)
	{
		if (cur->data > value)
		{
			parent = cur;
			cur = cur->lchild;
		}
		else if (cur->data < value)
		{
			parent = cur;
			cur = cur->rchild;
		}
		else
		{
			return;
		}
	}
	// �ж��ڵ�ǰ�ڵ�ĸ��ڵ�����ӻ����Һ��Ӳ��롣
	if (parent->data > value)
	{
		parent->lchild = CreatSearchTree(value);
	}
	else
	{
		parent->rchild = CreatSearchTree(value);
	}
}


// �������е�ĳ��Ԫ�ص�λ��(����������)���ǵݹ飩
SearchTreeNode *SearchTreeFind1(SearchTreeNode *root, SearchTreeType to_find)
{
	if (root == NULL)
	{
		return NULL;
	}
	SearchTreeNode *cur = root;
	while (cur != NULL)
	{
		if (cur->data > to_find)
		{
			cur = cur->lchild;
		}
		else if (cur->data < to_find)
		{
			cur = cur->rchild;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

// ɾ������ĳ��Ԫ�أ��ǵݹ飩
void SearchTreeRemove1(SearchTreeNode **root, SearchTreeType value)
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		return;
	}
	SearchTreeNode *to_delete = *root;
	SearchTreeNode *parent = NULL;
	// 1.ѭ���ҵ���ӦԪ�ص�λ�á�
	while (to_delete != NULL)
	{
		if (to_delete->data > value)
		{
			parent = to_delete;
			to_delete = to_delete->lchild;
		}
		else if (to_delete->data < value)
		{
			parent = to_delete;
			to_delete = to_delete->rchild;
		}
		else
		{
			break;
		}
	}
	if (to_delete != NULL)
	{
		// 2.����ж���ڵ�
		
		if (to_delete->lchild == NULL && to_delete->rchild == NULL)
		{
			//  ֻ��һ�����ڵ㡣
			if ((*root)->data == value)
			{
				DestroyTreeNode(to_delete);
				*root = NULL;
				return;
			}
			// ������Ҷ�ӽڵ㡣
			// ���ʱ��parent->dataһ���������value
			if (parent->data > value)
			{
				parent->lchild = NULL;
				DestroyTreeNode(to_delete);
			}
			else
			{
				parent->rchild = NULL;
				DestroyTreeNode(to_delete);
			}
		}
		else if (to_delete->lchild != NULL && to_delete->rchild == NULL)
		{
			//   ֻ��������.
			if (parent->lchild == to_delete)
			{
				parent->lchild = to_delete->lchild;
				DestroyTreeNode(to_delete);
			}
			else
			{
				parent->rchild = to_delete->lchild;
				DestroyTreeNode(to_delete);
			}
		}
		else if (to_delete->lchild == NULL && to_delete->rchild != NULL)
		{
			//   ֻ��������
			if (parent->lchild == to_delete)
			{
				parent->lchild = to_delete->rchild;
				DestroyTreeNode(to_delete);
			}
			else
			{
				parent->rchild = to_delete->rchild;
				DestroyTreeNode(to_delete);
			}
		}
		else
		{
			//   ������������
			SearchTreeNode *cur = to_delete->rchild;
			parent = to_delete;
			while (cur->lchild != NULL)
			{
				parent = cur;
				cur = cur->lchild;
			}
			to_delete->data = cur->data;
			if (parent->rchild == cur)
			{
				parent->rchild = cur->rchild;
				DestroyTreeNode(cur);
			}
			else
			{
				parent->lchild = NULL;
				DestroyTreeNode(cur);
			}
		}
	}
	return;
}
#endif


// �������Ĳ���ݹ����
void SearchTreeInsert(SearchTreeNode **root, SearchTreeType value)
{
	if (root == NULL)
	{
		return;
	}
	if (*root == NULL)
	{
		*root = CreatSearchTree(value);
		return;
	}
	if ((*root)->data > value)
	{
		SearchTreeInsert(&(*root)->lchild, value);
	}
	else
	{
		SearchTreeInsert(&(*root)->rchild, value);
	}
	return;
}

// �������е�ĳ��Ԫ�ص�λ��(�ݹ����)
SearchTreeNode *SearchTreeFind(SearchTreeNode *root, SearchTreeType to_find)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == to_find)
	{
		return root;
	}
	SearchTreeNode *lchild = SearchTreeFind(root->lchild,to_find);
	SearchTreeNode *rchild = SearchTreeFind(root->rchild, to_find);
	if (lchild != NULL)
	{
		return lchild;
	}
	if (rchild != NULL)
	{
		return rchild;
	}
	return NULL;
}

// ɾ������ĳ��Ԫ��
void SearchTreeRemove(SearchTreeNode **root, SearchTreeType value)
{
	if (root == NULL || *root == NULL)
	{
		return;
	}
	// 1.�Ȳ��ҳ�Ҫɾ����Ԫ��
	if (value < (*root)->data)
	{
		SearchTreeRemove(&(*root)->lchild, value);
	}
	else if (value >(*root)->data)
	{
		SearchTreeRemove(&(*root)->rchild, value);
	}
	else
	{
		// 2.ɾ����Ϊ4������
		SearchTreeNode *remove = *root;
		// a��ֻ��һ���ڵ����Ҷ�ӽڵ�
		if (remove->lchild == NULL && remove->rchild == NULL)
		{
			*root = NULL;
			free(remove);
			return;
		}
		// b��ֻ��������
		else if (remove->lchild != NULL && remove->rchild == NULL)
		{
			*root = remove->lchild;
			free(remove);
			return;
		}
		// c��ֻ��������
		else if (remove->lchild == NULL && remove->rchild != NULL)
		{
			*root = remove->rchild;
			free(remove);
			return;
		}
		// d��������������
		else
		{
			SearchTreeNode *min = remove->rchild;
			while (min->lchild != NULL)
			{
				min = min->lchild;
			}
			remove->data = min->data;
			SearchTreeRemove(&remove->rchild, min->data);
			return;
		}
	}
}

////////////////////////
#if 1
void PreOrder(SearchTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}

void InOrder(SearchTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	printf("%c", root->data);
	InOrder(root->rchild);
}

void TestSearchTreeInsert()
{
	SearchTreeNode *root = NULL;
	SearchTreeInit(&root);
	SearchTreeInsert(&root,'b');
	SearchTreeInsert(&root,'a');
	SearchTreeInsert(&root,'c');
	SearchTreeInsert(&root,'d');
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
}

void TestSearchTreeFind()
{
	SearchTreeNode *root = NULL;
	SearchTreeInit(&root);
	SearchTreeInsert(&root, 'b');
	SearchTreeInsert(&root, 'a');
	SearchTreeInsert(&root, 'c');
	SearchTreeInsert(&root, 'd');
	SearchTreeNode *ret = SearchTreeFind(root, 'c');
	SearchTreeNode *ret1 = SearchTreeFind(root, 'g');
	printf("%p %c  %p\n", ret,ret->data, ret1);
}

void TestSearchTreeRemove()
{
	SearchTreeNode *root = NULL;
	SearchTreeInit(&root);
	SearchTreeInsert(&root, 'b');
	SearchTreeInsert(&root, 'a');
	SearchTreeInsert(&root, 'f');
	SearchTreeInsert(&root, 'd');
	SearchTreeInsert(&root, 'g');
	SearchTreeInsert(&root, 'h');
	SearchTreeInsert(&root, 'e');
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	SearchTreeRemove(&root,'d');
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	SearchTreeRemove(&root, 'a');
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
}

int main()
{
	TestSearchTreeInsert();
	printf("\n");
	printf("\n");
	TestSearchTreeFind();
	printf("\n");
	printf("\n");
	TestSearchTreeRemove();
	system("pause");
	return 0;
}
#endif