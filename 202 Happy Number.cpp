class Solution {
    bool mark[811];
    int getSquaredSum(int n) {
        int ans = 0;
        while(n) {
            int lastDigit = n%10;
            ans+= lastDigit * lastDigit;
            n/=10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        memset(mark,0,sizeof(mark));
        while(n != 1) {
            int squaredSum = getSquaredSum(n);
            if(mark[squaredSum])
                return false;
            mark[squaredSum] = true;
            n = squaredSum;
        }
        return true;
    }
};