#pragma once

#include <stdio.h>
#include <string>
#include <assert.h>
#include "HuffmanTree.h"

#define LEN 256

typedef long long LongType;

struct charInfo
{
	unsigned char ch;
	std::string code;
	LongType count;

	charInfo() :ch(0), code(""), count(0)
	{}

	charInfo operator+(const charInfo& info)
	{
		charInfo ret;
		ret.count = count + info.count;
		return ret;
	}

	// w1 > w2
	bool operator>(const charInfo& info)
	{
		return count > info.count;
	}

	bool operator!=(const charInfo& info)
	{
		return count != info.count;
	}
};

class FileCompress
{
	typedef HuffmanTreeNode<charInfo> TreeNode;

	struct TmpInfo //����д��Ͷ�����ѹ���ļ��У��Դ�������huffman��
	{
		char cha;
		LongType count;
	};

public:

	FileCompress()
	{
		for (size_t i = 0; i < LEN; ++i)
		{
			hashtableInfo[i].ch = i;
			hashtableInfo[i].count = 0;
		}
	}

	// ѹ
	void Compress(const char* file)
	{
		// ��ԭ�����ļ�
		FILE* fd = fopen(file, "rb");
		if (fd == NULL)
		{
			perror("fopen error\n");
			return;
		}

		// ͳ������
		char c = fgetc(fd);
		//c = fgetc(fd);
		//bi:
		while (!feof(fd))
		{
			hashtableInfo[(unsigned char)c].count++;
			c = fgetc(fd);
		}
		/*if ((c = fgetc(fd)) != EOF)
		{
			goto bi;
		}*/

		// ����huffman��
		charInfo invalid;
		invalid.count = 0;
		HuffmanTree<charInfo> huffman(hashtableInfo, 256, invalid);

		// ����ֽڵı���
		std::string code;
		GetCode(huffman.GetRoot(), code);

		// �������Ҵ��µ��ļ���
		std::string compressfile = file;
		compressfile += ".huffman";
		FILE* fin = fopen(compressfile.c_str(), "wb");
		assert(fin);

		// ��ѹ���ļ���д�빹��huffman��ch��count
		for (size_t i = 0; i < 256; ++i)
		{

			if (hashtableInfo[i].count > 0)
			{
				TmpInfo tmp;
				tmp.cha = hashtableInfo[i].ch;
				tmp.count = hashtableInfo[i].count;
				fwrite(&tmp, sizeof(TmpInfo), 1, fin);
			}
		}

		TmpInfo tmp;
		tmp.count = -1;
		fwrite(&tmp, sizeof(TmpInfo), 1, fin);


		// ѹ��
		fseek(fd, 0, SEEK_SET); // ��ԭ���ļ�ָ���Ƶ���ͷ
		c = fgetc(fd);
		char value = 0;
		size_t pos = 0;
		while (!feof(fd))
		{
			// ���ó�hash�ж�Ӧ�ַ��ı���,���Ұ��ձ���λд���ļ�
			std::string& code = hashtableInfo[(unsigned char)c].code;
			for (size_t i = 0; i < code.size(); ++i)
			{
				if (code[i] == '1')
				{
					value |= (1 << pos);
				}
				else if (code[i] == '0')
				{
					value &= (~(1 << pos));
				}
				else
				{
					assert(false);
				}
				++pos;
				if (pos == 8)
				{
					fputc(value, fin);
					value = 0;
					pos = 0;
				}
			}
			c = fgetc(fd);
		}
		if (pos > 0)
		{
			fputc(value, fin);
		}

		fclose(fd);
		fclose(fin);
	}

	// ��ȡ�ַ���ʾ�Ķ�������
	void GetCode(TreeNode* root, std::string code)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			hashtableInfo[(unsigned char)root->data.ch].code = code;
			return;
		}
		GetCode(root->left, code + '0');
		GetCode(root->right, code + '1');
	}

	//////////////////////////////////////////
	//////////////////////////////////////////
	// ��ѹ
	void Uncompress(const char* file)
	{
		// ��ԭ�ļ�����
		std::string uncompress = file;
		size_t pos = uncompress.rfind(".");
		if (pos == std::string::npos)
		{
			assert(false);
		}
		uncompress.erase(pos); //��posɾ��β��Ĭ����string::npos

		// ��Ҫ��ѹ��,��Ҫд����ļ�
		FILE* fout = fopen(uncompress.c_str(), "wb");
		assert(fout);

		// ��ѹ���ļ�
		FILE* fd = fopen(file, "rb");
		assert(fd);
		TmpInfo tmp;
		fread(&tmp, sizeof(TmpInfo), 1, fd);
		while (tmp.count != -1)
		{
			hashtableInfo[(unsigned char)tmp.cha].ch = tmp.cha;
			hashtableInfo[(unsigned char)tmp.cha].count = tmp.count;
			fread(&tmp, sizeof(TmpInfo), 1, fd);
		}
		// �ؽ�huffman��
		charInfo invalid;
		invalid.count = 0;
		HuffmanTree<charInfo> tree(hashtableInfo, 256, invalid);
		TreeNode* root = tree.GetRoot();
		LongType n = root->data.count;

		TreeNode* cur = root;
		char c = 0;
		c = fgetc(fd);
		while (1)
		{
			
			for (size_t i = 0; i < 8; ++i)
			{
	
				if ((c & (1 << i))) // ��Ϊ�������0�����������һλΪ0������ֵ��Ϊ1����Ϊ�ͻ�ת��intֵ
				{
					cur = cur->right;
				}
				else
				{
					cur = cur->left;
				}

				if (cur->left == NULL && cur->right == NULL)
				{
					putc(cur->data.ch, fout); // д���ļ���ȥ
					cur = root;
					if (--n == 0) // ������󼸸�����λ
					{
						fclose(fd);
						fclose(fout);
						return;
					}
				}
			}
			c = fgetc(fd);
		/*char value = fgetc(fd);
		pos = 0; 
			for (;;){
				if (value & (1 << pos))
					cur = cur->right;
				else
					cur = cur->left;
				++pos;

				if (NULL == cur->left && NULL == cur->right){
					fputc(cur->data.ch, fout);
					cur = root;
					if (--n == 0)
						break;
				}
				if (pos > 7){
					value = fgetc(fd);
					pos = 0;
				}
			}*/

		}
		fclose(fd);
		fclose(fout);
	}


protected:
	charInfo hashtableInfo[LEN];
};
