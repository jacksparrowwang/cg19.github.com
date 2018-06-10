/*쳲��������� */
/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n��
�������쳲��������еĵ�n�
n<=39
*/
// 1��1��2��3��5��8...
 int Fibonacci(int n) {
        if (n <= 0)
        {
            return 0;
        }
        if (n <= 2) // ���С�ڵ���2˵��Ϊ1
        {
            return 1;
        }
        int front = 1;
        int mid = 1;
        int cur = 0;
        while (n > 2) // �Ǹ�ֵ��ϵ�Ǻ��汻ǰ��ĸ�ֵ�Ϳ���
        {
            cur = front + mid;
            front = mid;
            mid = cur;
            --n;
        }
        return cur;
    }
	
// 쳲���������
/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
*/	
// 1,2,3,5,8,13...
    int jumpFloor(int number) {
        if (number <=0)
        {
            return 0;
        }
        if (number <= 3) 
        {
            return number;
        }
        int front = 1;
        int mid = 2;
        int cur = 0;
        while (number > 2)
        {
            cur = front + mid;
            front = mid;
            mid = cur;
            --number;
        }
        return cur;
    }
	
/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/

//2F(N)
// 1, 2, 4, 8, 16, 32...
    int jumpFloorII(int number) {
        if (number <= 0)
        {
            return 0;
        }
        if (number <= 2)
        {
            return number;
        }
        int front = 2;
        int cur = 0;
        while (number > 2)
        {
            cur = 2*front;
            front = cur;
            --number;
        }
        return cur;
    }