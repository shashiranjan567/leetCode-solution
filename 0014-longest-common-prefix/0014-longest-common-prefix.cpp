class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];  // take first string as prefix
        
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) { // check if prefix matches start of strs[i]
                prefix = prefix.substr(0, prefix.size() - 1); // shrink prefix
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};