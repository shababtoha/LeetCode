class Solution {
    double calculatePow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;
        double res = calculatePow(x, n/2);
        return (n&1) ? res * res * x : res * res;
    }
public:
    double myPow(double x, int n) {
        bool neg = n < 0;
        double ans = calculatePow(x, abs(n));
        return neg ? (1.0/ans) : ans;
    }
};