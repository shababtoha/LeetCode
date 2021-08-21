class Solution {
    pair<int, int> calculate(const string &s, int index) {
        int total = 0;
        int curNum = 0;
        bool isAdd = true;
        while(index < s.size()) {
            if(s[index] == ' '){
                index++;
                continue;
            } else if(s[index] == '+' || s[index] == '-') {
                total = addOrSubstract(total, curNum, isAdd);
                isAdd = (s[index] == '+');
                curNum = 0;
                index++;
            } else if(s[index] == '(') {
                pair<int, int> recursiveCalculate = calculate(s, index+1);
                curNum = recursiveCalculate.first;
                index = recursiveCalculate.second;
            } else if(s[index] == ')') {
                return {addOrSubstract(total, curNum, isAdd), index + 1};
            } else {
                curNum = curNum * 10 + (s[index] - '0');
                index++;
            }
        }
        return {addOrSubstract(total, curNum, isAdd), s.size()};
    }
    
    int addOrSubstract(int total, int cur, bool isAdd) {
        return isAdd ? total + cur : total - cur;
    }
public:
    int calculate(string s) {
        return calculate(s, 0).first;
    }
};