class Solution {
public:
    string removeOuterParentheses(string s) {
       /*int  count  = 0;
       string ans  = "";
       for (int i = 0; i < s.length(); i++){
        if(s[i] == ')') count --;
        if(count != 0) ans.push_back(s[i]);
        if(s[i] == '(') count++;
       } 
       return ans;*/

        string result = "";
        stack<char> stk;
        int start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push('(');
            } else {
                stk.pop();
            }

        // When the stack is empty, we have a complete primitive
            if (stk.empty()) {
            // Add the inner part (excluding outermost)
                result += s.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        return result;
    }
   
};