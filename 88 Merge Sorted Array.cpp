class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = n + m -1;
        m--;
        n--;
        while(sz>=0) {
            if(m >= 0 && n >= 0) {
                if(nums1[m] > nums2[n]) {
                    nums1[sz--] = nums1[m--];
                } else {
                    nums1[sz--] = nums2[n--];
                }
            } else if(m >= 0) {
                nums1[sz--] = nums1[m--];
            } else {
                nums1[sz--] = nums2[n--];
            }
        }
    }
};