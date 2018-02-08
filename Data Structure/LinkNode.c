#include"LinkNode.h"

//��ӡ
void LinkNodePrint(LinkNode *head)
{
	LinkNode* cur = NULL;
	printf("head:");
	if(head == NULL)
	{
		//������
		return;
	}
	cur = head;
	
	while(cur != NULL)
	{
		printf("[%c:%p]-> ",cur->data,&cur->data);
		cur = cur->next;
	}
	printf("NULL\n\n");
}

//�Ե�������г�ʼ��
void InitLinkNode(LinkNode **head)
{
	if (head == NULL)
	{
		// �Ƿ����롣
		return;
	}
	*head = NULL;
}

//�����ڵ�
LinkNode *CreatNode(TypeChar value)
{
	LinkNode* new_node = (LinkNode *)malloc(sizeof(LinkNode));
	if(new_node == NULL)
	{
		//�����ڴ�ʧ�ܡ�
		return NULL;
	}
	new_node->next = NULL;
	new_node->data = value;
	return new_node;
}

//�Ե��������β��;
LinkNode* PushBackLinkNode(LinkNode **head, TypeChar value)
{
	LinkNode *new_node = NULL;
	LinkNode *cur = NULL; 
	if(head == NULL)
	{
		//�Ƿ�����
		return NULL;
	}
	new_node = CreatNode(value);
	if(*head == NULL)
	{
		*head = new_node;
		return *head;
	}
	cur = *head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = new_node;
	return new_node;
}

//�Ե��������βɾ
void PopBackLinkNode(LinkNode **head)
{
	LinkNode* to_delete = NULL;
	LinkNode* cur = *head;
	if (head == NULL)
	{
		//�Ƿ����롣
		return ;
	}
	if (*head == NULL)
	{
		//Ϊ������
		return;
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	to_delete = cur->next;
	free(to_delete);
	cur->next = NULL;
	return;
}

//�Ե��������ͷ��
void PushFrontLinkNode(LinkNode** head, TypeChar value)
{
	LinkNode* cur = NULL;
	if (head == NULL)
	{
		//�Ƿ����롣
		return;
	}
	cur = CreatNode(value);
	cur->next = *head;
	*head = cur;
}

//�Ե��������ͷɾ
void PopFrontLinkNode(LinkNode** head)
{
	LinkNode* cur = NULL;
	if (head ==NULL)
	{
		//�Ƿ����롣
		return;
	}
	if (*head == NULL)
	{
		//Ϊ���б�
		return;
	}
	cur = (*head)->next;
	free(*head);
	*head = cur;
}

//�Ե��������ֵλ�õĲ��ң����ض�Ӧֵ�ĵ�ַ
LinkNode* FindLinkNode(LinkNode* head, TypeChar value)
{
	LinkNode* cur = NULL;
	if (head == NULL)
	{
		//������
		return NULL;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->data == value)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�������ָ��λ��֮ǰ����Ԫ�أ���ͨ�ŷ���,ʱ�临�Ӷ�O(n)
void InsertFrontLinkNode(LinkNode** head, LinkNode* pos, TypeChar value)
{
	LinkNode* new_node = NULL;
	LinkNode* cur = NULL;
	if (head == NULL || pos == NULL)
	{
		//�Ƿ����롣
		return;
	}
	if (*head == NULL)
	{
		//������Ϊ�ա�
		return;
	}
	cur = *head;
	if (cur == pos)   //��ͷ�ڵ�����жϣ��Ƿ���pos.
	{
		PushFrontLinkNode(head, value);
		return;
	}
	while (cur->next != NULL)
	{
		if (cur->next == pos)
		{
			new_node = CreatNode(value);
			cur->next = new_node;
			new_node->next = pos;
			return;
		}
		cur = cur->next;
	}
	return;
}

//�������ָ��λ��֮ǰ����Ԫ�ء����ƻ���ľ�󷨣�ʱ�临�Ӷ�Ϊo(1).
void InsertFrontLinkNode1(LinkNode** head, LinkNode* pos, TypeChar value) //posֵ����Ҫ�ǺϷ��ڵ�
{
	LinkNode* new_node = NULL;
	if (head == NULL || pos == NULL)
	{
		//�Ƿ����롣
		return;
	}
	if (*head == NULL)
	{
		//����Ϊ�ա�
		return;
	}
	new_node = CreatNode(pos->data);
	new_node->next = pos->next;
	pos->next = new_node;
	pos->data = value;
}

//�ڵ�����ָ��λ��֮�����Ԫ�ء�
void InsertAfterLinkNode(LinkNode* head, LinkNode* pos, TypeChar value)
{
	// ��Ϊ���ڵ�����֮�����Ԫ�أ����Բ���ı�ͷָ�룬������* ������**
	LinkNode* new_node = NULL;
	if (head == NULL || pos == NULL)
	{
		//����Ϊ������
		return;
	}
	new_node = CreatNode(value);
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}

//ɾ��������������ָ��λ�õĽڵ㡣ʱ�临�Ӷ�Ϊo(n)
void EraseLinkNode(LinkNode** head, LinkNode* pos)
{
	LinkNode* cur = NULL;
	if (head == NULL || pos == NULL)
	{
		// �Ƿ����롣
		return;
	}
	if (*head == NULL)
	{
		//����Ϊ�ա�
		return;
	}
	if (*head == pos)
	{
		*head = (*head)->next;
		free(pos);
		return;
	}
	cur = *head;
	while (cur->next != NULL)
	{
		if (cur->next == pos)
		{
			cur->next = pos->next;
			pos->next = NULL;
			break;
		}
		cur = cur->next;
	}
	free(pos);
}

//ɾ����������ָ��λ�õĽڵ㣬������β�ڵ㣩ʱ�临�Ӷ�Ϊo(1).
void EraseLinkNode1(LinkNode* head, LinkNode* pos)
{
	LinkNode* temp = NULL;
	if (head == NULL || pos == NULL)
	{
		//����Ϊ�գ�pos�Ƿ���
		return;
	}
	temp = pos->next;
	pos->data = temp->data;
	pos->next = temp->next;
	free(temp);
	return;
}

//ɾ��ָ��ֵ�Ľڵ㣬������ͷ�������е�һ�����ֵ�ֵ�Ľڵ㣩
void RemoveLinkNode(LinkNode** head, TypeChar value)
{
	LinkNode* cur = NULL;
	LinkNode* temp = NULL;
	if (head == NULL)
	{
		//�Ƿ����롣
		return ;
	}
	if (*head == NULL)
	{
		//������
		return ;
	}
	cur = *head;
	if (cur->data == value)  //ͷ�ڵ㡣
	{
		*head = (*head)->next;
		free(cur);
		return ;
	}
	while (cur->next != NULL)
	{
		if (cur->next->data == value)
		{
			temp = cur->next;        //��ֵһ��Ҫע�Ᵽ��ԭ��ָ��ָ��ĵ�ַ���Ա����ͷ��ڴ档
			cur->next = cur->next->next;//�����׻�ͼ��
			free(temp);
			break;
		}
		cur = cur->next;
	}
	
}

//ɾ��ָ��ֵ������Ԫ�ء�
void RemoveLinkNodeAll(LinkNode** head, TypeChar value)
{
	LinkNode* pos = NULL;
	int ret = 1;
	while (ret)
	{
		pos = FindLinkNode(*head, value);
		if (pos == NULL)
		{
			ret = 0;
		}
		EraseLinkNode(head, pos);
	}
	//LinkNode* cur = NULL;
	//LinkNode* temp = NULL;
	//LinkNode* keep = NULL;
	//LinkNode* sb = NULL;
	//if (head == NULL)
	//{
	//	// �Ƿ����롣
	//	return;
	//}
	//if (*head == NULL)
	//{
	//	// ������
	//	return;
	//}
	//temp = *head;
	//if ((*head)->data == value)
	//{
	//	*head = (*head)->next;
	//	free(temp);
	//}
	//keep = *head;
	//cur = (*head)->next;
	//while (cur->next != NULL)
	//{
	//	if (cur->data == value)
	//	{
	//		keep->next = cur->next;
	//		sb = cur;
	//	}
	//	else
	//	{
	//		keep = keep->next;
	//	}
	//	cur = cur->next;
	//	free(sb);
	//}
}

//�ж������Ƿ�Ϊ��
int EmotyLinkNode(LinkNode* head)
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

//��������
size_t SizeLinkNode(LinkNode* head)
{
	size_t count = 0;
	LinkNode* cur = NULL;
	cur = head;
	while (cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//�����������ӡ
void BackPrintLinkNode(LinkNode* head)
{
	if (head == NULL)
	{
		//Ϊ������
		return;
	}
	BackPrintLinkNode(head->next);
	printf("[%c: %p]",head->data,head);
}