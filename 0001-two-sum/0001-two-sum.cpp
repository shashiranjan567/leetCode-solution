class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores (value -> index)

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                // complement found, return indices
                return {mp[complement], i};
            }

            // store current number with its index
            mp[nums[i]] = i;
        }

        return {};
        
        
    }
};