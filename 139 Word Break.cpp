class Solution {
    const long long base = 31;
    const long long MOD = 1000000000 + 7;
    vector<bool> visited;
    vector<bool> dp;
    unordered_map<long long, bool> hashMap;
    
    long long getHash(const string &s) {
        long long hashValue = 0;
        for(char i : s) {
            hashValue = hashValue * base + i;
            hashValue%= MOD;
        }
        return hashValue;
    }
    
    bool solve(const string &s, int pos) {
        if(pos == s.size())
            return true;
        if(visited[pos])
            return dp[pos];
        visited[pos] = 1;
        long long hashValue = 0;
        int possible = false;
        for(int i = pos; i<s.size();i++) {
            hashValue = hashValue * base + s[i];
            hashValue %= MOD;
            if(hashMap[hashValue]) {
                possible |= solve(s, i+1);
            }
            if(possible)
                break;
        }
        return dp[pos] = possible;
        
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty())
            return false;
        hashMap.clear();
        for(string s: wordDict) {
            long long hashValue = getHash(s);
            hashMap[hashValue] = true;
        }
        dp.resize(s.size(), false);
        visited.resize(s.size(), false);
        
        return solve(s, 0);
    }
};