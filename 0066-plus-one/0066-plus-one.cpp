class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; 
                return digits; // no carry, done
            }
            digits[i] = 0; // set current digit to 0, carry goes to next
        }
        
        // if all digits were 9, e.g., 999 -> 1000
        digits.insert(digits.begin(), 1);
        return digits;
    }
};