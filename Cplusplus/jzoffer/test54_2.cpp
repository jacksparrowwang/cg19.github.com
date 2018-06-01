  
  
  /*������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��*/
   
   
   #include <iostream>
   #include <vector>
   
   vector<vector<int> > FindContinuousSequence(int sum) {
        int small = 1;
        int big = 2;
        int i = 0;
        vector<vector<int> > v;
        while (small <= sum/2 && big < sum)
        {
            int comb = (small+big)*(big-small+1)>>1;
            if (comb < sum)
            {
                ++big;
            }
            else if (comb > sum)
            {
                ++small;
            }
            else
            {
                vector<int> tmp;
                for (int j = small; j <= big; ++j)
                {
                    tmp.push_back(j);
                }
                v.push_back(tmp);
                ++i;
                ++big;
            }
        }
        return v;
    }