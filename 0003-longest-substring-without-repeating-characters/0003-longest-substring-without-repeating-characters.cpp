class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;  
        int maxLen = 0;
        int start = 0;  

        for (int end = 0; end < s.length(); ++end) {
            char ch = s[end];

           
            if (lastIndex.find(ch) != lastIndex.end() && lastIndex[ch] >= start) {
                start = lastIndex[ch] + 1;
            }

            lastIndex[ch] = end;  
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
        
   
};