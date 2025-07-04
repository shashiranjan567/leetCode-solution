class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty, return 0
        /*if (nums.empty()) return 0;
        
        // Initialize the index to place unique elements
        int k = 1;
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If current element is different from the previous unique element
            if (nums[i] != nums[k-1]) {
                // Place the unique element at the kth position
                nums[k] = nums[i];
                // Increment the unique elements count
                k++;
            }
        }
        
        // Return the number of unique elements
        return k;*/


        if (nums.empty()) return 0;

        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {

            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
    return i + 1;
    }
};