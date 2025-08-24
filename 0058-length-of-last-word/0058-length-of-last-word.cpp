class Solution {
public:
    int lengthOfLastWord(string s) {
       int i = s.size() - 1;
        
        // skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;
        
        int length = 0;
        // count characters of last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length; 
    }
};