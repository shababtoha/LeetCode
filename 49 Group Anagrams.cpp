class Solution {
    unordered_map <string, vector<string> > m; 
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        m.clear();
        vector<vector<string>> ans;
        for(string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            m[sortedStr].push_back(str);
        }
        for(auto const &x : m) {
            ans.push_back(x.second);
        }
        return ans;
    }
};