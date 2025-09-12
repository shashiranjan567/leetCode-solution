//Approach-1 (Using unordered set to keep track of frequencies)
//T.C : O(n) we don't visit any character more than once.
//S.C : O(n) - Set and note that freq is of size 26 which is of constant size
class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> st;
        int freq[26] = {0};
      
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            
            while(freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;
                result++;
            }
            st.insert(freq[i]);
        }
        
        return result;
    }
};

/*
//Approach-2 (Without using unordered_set)
//T.C : O(n) we don't visit any character more than once and sorting freq is O(26log26) = O(1)
//S.C : O(1) - Note that freq is of size 26 which is of constant size
class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        sort(begin(freq), end(freq));
        
        int result = 0;
        
        for(int i = 24; i >= 0 && freq[i] > 0; i--) {
            
            if(freq[i] >= freq[i+1]) {
                
                int prev = freq[i];
                
                freq[i] = max(0, freq[i+1]-1);
                
                result  += (prev - freq[i]);
                
            }
            
        }
          
        return result;
    }
};
*/

