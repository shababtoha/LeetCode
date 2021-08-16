class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(int i = 0 ; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        int index = 0;
        for(int i = 0; i<3;i++){
            while(cnt[i]--) 
                nums[index++] = i;
                
        }
    }
};