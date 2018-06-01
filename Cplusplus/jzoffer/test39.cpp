/*

��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ�
�������鳤�ȵ�һ�룬������2����������������0��

*/



    // ���ÿ���˼��
    int Partition(vector<int> numbers, int beg, int endd)
    {
        int value = numbers[endd-1];
        int end = endd-1;
        while (beg < end)
        {
            if (numbers[beg] <= value)
            {
                ++beg;
            }
            else if (numbers[end] >= value)
            {
                --end;
            }
            else
            {
                swap(numbers[beg], numbers[end]);
            }
        }
        swap(numbers[beg], numbers[end]);
        return beg;
    }
    // �������ҳ���λ��
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() < 1)
        {
            return 0;
        }
		// ������м��λ��
        int mid =  numbers.size()>>1;
        int beg = 0;
        int end = numbers.size()-1;
		// �ҵ���Ӧ���м�λ�õ���
        int index = Partition(numbers, beg, end);
        while (index != mid)
        {
			// ����м��������м�λ��
            if (index > mid)
            {
				// �ߵ�ǰ�벿��
                end = index - 1;
                index = Partition(numbers, beg, end);
            }
            else
            {
				// �ߺ�벿��
                beg = index + 1;
                index = Partition(numbers, beg, end);
            }
        }
		// �ҵ���
        int result = numbers[mid];
        
        // �������ж��ҵ�����λ�����ǲ��ǳ��������һ��
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (numbers[i] == result)
            {
                ++count;
            }
        }
		// �ҵ�����û�г���һ�룬2���ͻ�С�����ĳ���
        if (count*2 <= numbers.size())
        {
            return 0;
        }
        return result;
    }