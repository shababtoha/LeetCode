#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int ara[1001];
public:
    int jump(vector<int>& nums) {
        for(int i = 0 ; i< nums.size(); i++) {
            ara[i] = 10000000;
        }
        int lastIndex = nums.size()-1;
        ara[lastIndex] = 0;
        for(int i =  lastIndex - 1; i>=0; i--) {
            for(int j = i + 1 ; j <= lastIndex && j <= i+ nums[i]; j++) {
                ara[i] = min(ara[i], ara[j]+1);
            }
        }
        return ara[0];
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

    cout<< sol.jump(v)<<endl;

}
