#include<iostream>
#include<vector>
using namespace std;

class Solution {
    // find the first position of the array
    int mod(int size, int no) {
        return no >= size ? no - size : no;
    }

    int getPivotIndex (const vector<int>  nums) {
        int low = 0;
        int high = nums.size() - 1;
        int index = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] >= nums[0]) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return mod(nums.size(), index+1);
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        if(nums.size() == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int pivotIndex = getPivotIndex(nums);
        int low = pivotIndex;
        int arraySize = nums.size();
        int high = arraySize + pivotIndex - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mod(arraySize, mid)]) {
                return mod(arraySize, mid);
            } else if(target < nums[mod(arraySize, mid)]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
int main() {
    int n;
    cin>> n;
    vector<int> v;
    for(int i = 0 ;i<n;i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    while(true) {
        int target;
        cin>>target;
        Solution sol;
        cout<< sol.search(v, target) <<endl;
    }
}
