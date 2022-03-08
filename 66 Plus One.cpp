class Solution {
    
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index =  digits.size() - 1;
        while(carry && index >= 0) {
            digits[index] += carry;
            carry = 0;
            if(digits[index] > 9) {
                digits[index] = 0;
                carry = 1;
            }
            index--;
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};