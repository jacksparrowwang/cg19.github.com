#include "D_seqlist.h"

//��ӡ˳���
void seqlist_print(seqlist *seq)
{
	size_t i = 0;
	if(seq == NULL)
	{
		return ;
	}
	for(i=0; i< seq->size; i++)
	{
		printf("%c",seq->elem[i]);
	}
	return ;
}

//�Զ�̬˳���ĳ�ʼ��
void seqlist_init(seqlist *seq)
{
	if(seq == NULL)
	{
		return ;
	}
	seq->size = 0;
	seq->capacity = 1;
	seq->elem = (CHAR *)malloc(sizeof(CHAR) * seq->capacity);
}

//�����Ŀռ�����䣬ralloc
void seqlist_expand_capacity(seqlist *seq)
{
	size_t i = 0;
	CHAR *new_data = NULL;//ʹ��char����
	seq->capacity = 2 * seq->capacity + 1;
	new_data = (CHAR *)malloc(seq->capacity * sizeof(CHAR));
		for(i=0; i < seq->size; i++)
		{
			new_data[i] = seq->elem[i];
		}
		free(seq->elem);
		seq->elem = new_data;
}

//�Զ�̬˳������β��
void seqlist_push_back(seqlist *seq,CHAR value)
{
	if(seq == NULL)
	{
		return ;
	}
	if (seq->size >= seq->capacity)
	{
		seqlist_expand_capacity(seq);
	}
	seq->elem[seq->size] = value;
	seq->size++;
}

//��˳��������
void seqlist_destroy(seqlist *seq)
{
	if(seq == NULL)
	{
		return ;
	}
	seq->size = 0;
	seq->capacity = 0;
	free(seq->elem);
}


int main()
{
	seqlist_init(&seq);
	seqlist_push_back(&seq,'a');
	seqlist_push_back(&seq,'b');
	seqlist_push_back(&seq,'c');
	seqlist_push_back(&seq,'d');
	//seqlist_destroy(&seq);
	seqlist_print(&seq);
	return 0;
}