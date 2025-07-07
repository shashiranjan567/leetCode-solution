
class Solution {
public:
    string reverseWords(string s) {
        stringstream SS(s);
        string token;
        string result;

        while (SS >> token) {
            
            if (!result.empty()) {
                result = " " + result;
            }
            result = token + result;
        }

        return result;
    }
};
