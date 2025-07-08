class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++; // no change needed
            } 
            else if (bill == 10) {
                if (five == 0) return false; // can't give $5 change
                five--;
                ten++;
            } 
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
