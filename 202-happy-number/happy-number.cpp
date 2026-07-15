class Solution {
public:

    int nextNumber(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            int digit = n % 10;
            sum = sum + digit * digit;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        while(fast != 1)
        {
            fast = nextNumber(fast);

            if(fast != 1)
            {
                fast = nextNumber(fast);
                slow = nextNumber(slow);
            }

            if(slow == fast)
            {
                break;
            }
        }

        return fast == 1;
    }
};