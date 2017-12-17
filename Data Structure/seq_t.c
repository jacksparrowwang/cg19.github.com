
#include<stdio.h>
#include"sequence.h"


void show(seqlist *seq)  //��ӡ�б�
{
	size_t i = 0;
	for(i=0; i <(seq->size); i++)
	{
		printf("%c",seq->seq_t[i]);
	}
	printf("\n");
}


void initlist(seqlist *seq)  //��ʼ���б�
{
	seq->size = 0;
	assert(seq);
	seq->seq_t[seq->size] = 0;
}

void end_push_list(seqlist *seq,TYPECHAR value)  //β������һ��Ԫ��
{
	assert(seq);
	if(seq->size > sequence_table_max_length)
	{
		fprintf(stderr,"˳����Ȳ���\n");
		return ;
	}
	seq->seq_t[seq->size] = value;
	seq->size++;

}


void end_pop_list(seqlist *seq)  //β��ɾ��һ��Ԫ��
{
	assert(seq);
	if(seq->size <= 0)
	{
		fprintf(stderr,"�Ѿ��������ײ�\n");
		return;
	}
	seq->size--;
}



void frist_push_list(seqlist *seq,TYPECHAR value)  //�ײ�����һ��Ԫ��
{
	size_t i = 0;
	assert(seq);
	seq->size++;
	if(seq->size > sequence_table_max_length)
	{
		fprintf(stderr,"˳����Ȳ���\n");
	}
	for(i=seq->size; i>0; i--)
	{
		seq->seq_t[i] = seq->seq_t[i-1];
	}
	seq->seq_t[i] = value;//�±�Ϊ0

}

void frist_pop_list(seqlist *seq)  //��˳����ײ�ɾ��һ��Ԫ��
{
	size_t i = 0;
	assert(seq);
	seq->size--;
	for(i=0; i < seq->size; i++)
	{
		seq->seq_t[i] = seq->seq_t[i+1];
	}
	
}

//��ȡ����λ�õ�Ԫ�ء�addressΪλ�á�
void read_element_of_anywhere_address(seqlist *seq,size_t address)
{
	assert(seq);
	if(address > seq->size)
	{
		fprintf(stderr,"����Խ��\n");
	}
	printf(SHOWTYPE,seq->seq_t[address]);
}

//�޸�ָ��λ�õ�Ԫ�ء�addressΪ�޸ĵ��±ꡣvalueΪ�޸ĳɵ�ֵ��
void update_element_of_anywhere_address(seqlist *seq,size_t address,TYPECHAR value) 
{
	assert(seq);
	if(address > seq->size)
	{
		fprintf(stderr,"�޸�Խ��\n");
	}
	seq->seq_t[address] = value;
}

size_t gei_yuansu_chazhao_xiabiao(seqlist *seq,TYPECHAR value) // ��Ԫ�ز����±�subscript  value Ϊ����Ԫ��
{
	size_t i = 0;
	assert(seq);
	for(i=0; i<seq->size; i++)
	{
		if(seq->seq_t[i] == value)
		{
			printf("����Ԫ���±�Ϊ��%d\n",i);
			return i;
		}
	}
	if(i==seq->size)
	{
		printf("δ���ҵ�\n");	
	}
	return -1;
}


//������λ�ò���һ��Ԫ�ء�address�����λ�á�valueҪ�����ֵ��
void insert_element_of_anywhere_address(seqlist *seq,size_t address,TYPECHAR value)
{	
	size_t i = 0;
	assert(seq);
	seq->size++;
	if(seq->size > sequence_table_max_length)
	{
		fprintf(stderr,"˳����Ȳ���\n");
	}
	for(i = seq->size; i>address; i--)
	{
		seq->seq_t[i] = seq->seq_t[i-1];
	}
	seq->seq_t[i] = value;
}

//ɾ��ָ��λ�õ�Ԫ��
void seqListErase_address(seqlist* seq, size_t pos)
{
	size_t i = 0;
	assert(seq);
	if(pos > seq->size)
	{
		printf("δ���ҵ�\n");
		return ;
	}
	for(i=pos; i < seq->size; i++)
	{
		seq->seq_t[i] = seq->seq_t[i+1];
	}
	(seq->size)--;
	return ;
}

//����ָ����ֵ��ɾ��,����ظ�ֻɾ����һ����ʱ�临�Ӷ�ΪO��n��
void SeqListRemove(seqlist *seq, TYPECHAR to_delete)
{	
	size_t i = 0;
	assert(seq);
	i = gei_yuansu_chazhao_xiabiao(seq,to_delete);
	seqListErase_address(seq,i);
	return ;
}

//����ָ��ֵ��ɾ������������Ҫɾ����ֵ��ʱ�临�Ӷ�ΪO��n��
void SeqListRemoveAll(seqlist* seq, TYPECHAR to_delete)
{
	size_t count = 0;
	size_t i = 0;
	assert(seq);
	for(i = 0; i < seq->size; i++)
	{
		if(seq->seq_t[i] != to_delete)
		{
			seq->seq_t[i-count] = seq->seq_t[i];
		}
		else
		{
			count++;
		}
	}
	seq->size-=count;
	return ;
}


//��ȡ˳�����Ԫ�صĸ���
size_t SeqListSize(seqlist* seq)
{
	assert(seq);
	return seq->size;
}

//�ж�˳����Ƿ�Ϊ��,Ϊ�շ���1����Ϊ�շ���0��
int SeqListEmpty(seqlist* seq)
{
	assert(seq);
	if (seq->size == 0)
	{
		return 1;
	}
		return 0;
}


//����
void swap(char *p, char *q)
{
	char temp = *p;
	*p = *q;
	*q = temp;
}

//ð������
void SeqListBubbleSort(seqlist* seq)
{
	size_t i = 0;
	size_t j = 0;
	assert(seq);
	for(i = 0; i < seq->size-1; i++)
	{
		for(j = 0; j < seq->size-i-1; j++)
		{
			if(seq->seq_t[j] > seq->seq_t[j+1])
			{
				swap(&(seq->seq_t[j]),&(seq->seq_t[j+1]));
			}
		}
	}
}

//�ص�����
int cmp(TYPECHAR value1,TYPECHAR value2)
{
	return value1 - value2 ;
}

//�ص�����ð������
void SeqListBubbleSortEx(seqlist* seq, INT (*cmp)(TYPECHAR , TYPECHAR))
{
	size_t i = 0;
	size_t j = 0;
	assert(seq);
	for (i = 0; i < seq->size-1; i++)
	{
		for (j = 0; j < seq->size-i-1; j++)
		{
			if (cmp(seq->seq_t[j],seq->seq_t[j+1]) >0)
				swap(&(seq->seq_t[j]),&(seq->seq_t[j+1]));
		}
	}
}


int main()
{
	initlist(&seq);
	end_push_list(&seq,'a');
	end_push_list(&seq,'b');
	end_push_list(&seq,'c');
	end_push_list(&seq,'b');
	//end_pop_list(&seq);
	//frist_push_list(&seq,'d');
	//frist_push_list(&seq,'e');
	//frist_pop_list(&seq);
	//read_element_of_anywhere_address(&seq,0);//�����±��Ԫ��
	//update_element_of_anywhere_address(&seq,2,'q');//�޸�ָ��λ�õ�Ԫ��
	//gei_yuansuh_shibie_xiabiao(&seq,'b');//����Ԫ�ز��ҳ�Ԫ�ص��±�
	//insert_element_of_anywhere_address(&seq,0,'w');//������λ�ò���Ԫ��
	//seqListErase_address(&seq,4);//ɾ��ָ��λ�õ�Ԫ��
	//SeqListRemove(&seq,'b');//ɾ������ֵ��˳����еĵ�һ��Ԫ��
	//SeqListRemoveAll(&seq,'c');//ɾ������ָ��ֵ������Ԫ��
	//printf("%lu",SeqListSize(&seq));//����˳����еĸ���
	//printf("%d",SeqListEmpty(&seq));//�жϿ�˳���
	//SeqListBubbleSort(&seq);//ð������
	//SeqListBubbleSortEx(&seq, cmp);//�ص�����ð������Ĳ���
	show(&seq);
	return 0;
}