class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int num=x;
        // Handling negative numbers
        long long rev_num = 0;
	  while (num != 0)
	{
		int curr_digit = num % 10;

		rev_num = (rev_num * 10) + curr_digit;
        if(rev_num>INT_MAX)
            return 0;

		num = num / 10;
	}
    if(rev_num==x)
        return true;
        else
            return false;
    }
};
