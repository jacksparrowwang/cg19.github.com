/*
��һ���ַ���(1<=�ַ�������<=10000��
ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*/

#include <iostream>
#include <string>

  int FirstNotRepeatingChar(string str) {
        if (str.size()<1)
        {
            return -1;
        }
        // ���������������������ϣ��
        int hash[256] = {0};
        for (int i = 0; i < str.size(); ++i)
        {
            // �ַ���asii��Ϊ�±꣬ ���ֵĴ���Ϊ�������ֵ
            hash[str[i]]++;
        }
        for (int i = 0; i < str.size(); ++i)
        {
            // �ٰ��ַ�����ͷ���ʣ��ҳ���һ�γ��ֵ��ַ�
            if (hash[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }