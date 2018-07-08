#pragma once

#include <queue>
#include <vector>

template<class T>
struct HuffmanTreeNode
{
	T data;
	HuffmanTreeNode<T>* left;
	HuffmanTreeNode<T>* right;

	HuffmanTreeNode(const T& data) // �ڵ�Ĺ��캯��
		:data(data), left(NULL), right(NULL)
	{}
};

template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> TreeNode; // ���ڵ���������

	struct CompareTreeNode // �ṩһ���ڲ�����ʵ��һ���º��������������ȼ������ṩ�Ƚ�
	{
		bool operator()(TreeNode* l, TreeNode* r)
		{
			return l->data > r->data;
		}
	};

public:

	HuffmanTree(){};

	HuffmanTree(T* arr, size_t size, const T& invalid)// �����arr��һ�������hash��
	{
		std::priority_queue<TreeNode*, std::vector<TreeNode*>, CompareTreeNode> minheap; //Ĭ��Ϊ��� С�ں�
		for (size_t i = 0; i < size; ++i)
		{
			if (arr[i] != invalid)
			minheap.push(new TreeNode(arr[i])); // �Ƚ���һ��С��
		}
		while (minheap.size() > 1) // ע�� 
		{
			// ������ô���ܰ��׻�ȥ�ĸ��������ȡ������С�ڵ����ֿ�
			// �ýڵ��ָ��
			TreeNode* top1 = minheap.top(); 
			minheap.pop();
			TreeNode* top2 = minheap.top();
			minheap.pop();
			TreeNode* parent = new TreeNode(top2->data + top1->data);
			parent->left = top1;
			parent->right = top2;
			minheap.push(parent); //�����Զ��ʣ��һ��
		}
		root = minheap.top();
	}

	TreeNode* GetRoot() // �ⲿ�ṩ����root
	{
		return root;
	}

	~HuffmanTree()
	{
		Destory(root);
		root = NULL;
	}

	void Destory(TreeNode* root) //����ʱ��ĵݹ麯��
	{
		if (root == NULL)
		{
			return;
		}
		Destory(root->left);
		Destory(root->right);
		delete root;
	}


private:
	HuffmanTree(const HuffmanTree<T>& h);
	HuffmanTree<T> operator=(const HuffmanTree<T>& h);

protected:
	TreeNode* root;
};

//void TestHuffmanTree()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	HuffmanTree<int> hm(a, sizeof(a) / sizeof(int), 0);
//}
