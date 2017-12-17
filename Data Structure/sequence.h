#pragma once
#include<assert.h>
#define sequence_table_max_length 100
#define TYPECHAR char
#define SHOWTYPE "%c"

typedef int INT;

typedef struct seqlist
{
	size_t size ;
	TYPECHAR seq_t [sequence_table_max_length];
	
}seqlist;

seqlist seq ;

void show(seqlist *seq);
void initlist(seqlist *seq);

//β������һ��Ԫ��
void end_push_list(seqlist *seq,TYPECHAR value);

//β��ɾ��һ��Ԫ��
void end_pop_list(seqlist *seq);

//�ײ�����һ��Ԫ��
void frist_push_list(seqlist *seq,TYPECHAR value);

//��˳����ײ�ɾ��һ��Ԫ��
void frist_pop_list(seqlist *seq);

//��ȡ����λ�õ�Ԫ�ء�addressΪλ�á�
void read_element_of_anywhere_address(seqlist *seq,size_t address);

//�޸�ָ��λ�õ�Ԫ�ء�addressΪ�޸ĵ��±ꡣvalueΪ�޸ĳɵ�ֵ��
void update_element_of_anywhere_address(seqlist *seq,size_t address,TYPECHAR value);

// ��Ԫ�ز����±�subscript  value Ϊ����Ԫ��
void gei_yuansuh_shibie_xiabiao(seqlist *seq,TYPECHAR value);

//������λ�ò���һ��Ԫ�ء�address�����λ�á�valueҪ�����ֵ��
void insert_element_of_anywhere_address(seqlist *seq,size_t address,TYPECHAR value);

//ɾ��ָ��λ�õ�ֵ
void seqListErase_address(seqlist *seq, size_t pos);

//����ָ��ֵ��ɾ��������ظ�ֻɾ����һ����
void SeqListRemove(seqlist* seq, TYPECHAR to_delete); 

//����ָ��ֵ��ɾ������������Ҫɾ����ֵ��ʱ�临�Ӷ�ΪO��n��
void SeqListRemoveAll(seqlist* seq, TYPECHAR to_delete);

//��ȡ˳����е�Ԫ��
size_t SeqListSize(seqlist* seq);

//�ж�˳����Ƿ�Ϊ��,Ϊ�շ���1����Ϊ�շ���0��
int SeqListEmpty(seqlist* seq);

//ð������
void SeqListBubbleSort(seqlist* seq); 

//�ص�����ð������
void SeqListBubbleSortEx(seqlist* seq, INT (*cmp)(TYPECHAR , TYPECHAR));