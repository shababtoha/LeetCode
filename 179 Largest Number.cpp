class Solution {
    int getSize(int n) {
        if(n == 0)
            return 1;
        int len = 0;
        while(n) {
            len++;
            n/=10;
        }
        return len;
    }
    bool comparefn(int a, int b) {
        long long szA = getSize(a);
        long long szB = getSize(b);
        long long num1 = (long long)a * pow(10L, szB) + (long long) b;
        long long num2 = (long long)b * pow(10L, szA) + (long long) a;
        return num1 > num2;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        bool isNumberPresent = false;
        for(int a : nums) {
            if(a)
                isNumberPresent = true;
            v.push_back(to_string(a));
        }
        if(!isNumberPresent)
            return "0";
        sort(nums.begin(), nums.end(),[this](int a, int b){
             return comparefn(a,b);
        });
        string ans = "";
        for(int a : nums) {
            ans += to_string(a);
        }
        return ans;
    }
};