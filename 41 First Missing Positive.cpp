#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        bool oneExist = false;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                oneExist = true;
            }
            if(nums[i] <= 0 || nums[i] > size) {
                nums[i] = 1;
            }
        }
        if(!oneExist) {
            return 1;
        }

        for(int i = 0 ; i < size ;i++) {
            int x = nums[i];
            if(x < 0) {
                x = -x;
            }
            if(nums[x-1] >= 0) {
                nums[x-1] *= -1;
            }
        }
        for(int i = 1 ; i <= size; i++) {
            if(nums[i-1] > 0) {
                return i;
            }
        }
        return size+1 ;
    }
};


int main() {
    Solution sol;
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0 ;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }

    cout<< sol.firstMissingPositive(v)<<endl;

}
