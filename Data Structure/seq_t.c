
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

void gei_yuansu_chazhao_xiabiao(seqlist *seq,TYPECHAR value) // ��Ԫ�ز����±�subscript  value Ϊ����Ԫ��
{
	size_t i = 0;
	assert(seq);
	for(i=0; i<seq->size; i++)
	{
		if(seq->seq_t[i] == value)
		{
			printf("����Ԫ���±�Ϊ��%d\n",i);
			break;
		}
	}
	if(i==seq->size)
	{
		printf("δ���ҵ�\n");	
	}
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


int main()
{
	initlist(&seq);
	//end_push_list(&seq,'a');
	//end_push_list(&seq,'b');
	//end_push_list(&seq,'c');
	//end_pop_list(&seq);
	//frist_push_list(&seq,'d');
	//frist_push_list(&seq,'e');
	//frist_pop_list(&seq);
	//read_element_of_anywhere_address(&seq,0);
	//update_element_of_anywhere_address(&seq,2,'q');
	//gei_yuansuh_shibie_xiabiao(&seq,'b');
	//insert_element_of_anywhere_address(&seq,0,'w');
	show(&seq);
	return 0;
}