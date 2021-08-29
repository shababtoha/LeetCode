class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int uniqueIndex = 0;
        int duplicateIndex = 0;
        while(duplicateIndex < nums.size() ) {
            if(nums[uniqueIndex] == nums[duplicateIndex]) {
                duplicateIndex++;
            } 
            else {
                nums[++uniqueIndex] = nums[duplicateIndex];
            }
        }
    
        return uniqueIndex + 1;
    }
};