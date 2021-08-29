class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int rabbit = 0;
        int torToise = 0;
        while(true) {
            rabbit = nums[nums[rabbit]];
            torToise = nums[torToise];
            if(rabbit  == torToise)
                break;
        }
        rabbit = 0;
        while(rabbit != torToise) {
            rabbit = nums[rabbit];
            torToise = nums[torToise];
        }
        return rabbit;
    }
};